#include <arrow/api.h>
#include <vector>
#include "nif_utils.h"

#define IF_TYPE(atom, type)                  \
    if (enif_compare(arrow_type, atom) == 0) \
    {                                        \
        adt = type;                          \
    }

#define ELSE_IF_TYPE(atom, type)                  \
    else if (enif_compare(arrow_type, atom) == 0) \
    {                                             \
        adt = type;                               \
    }

ERL_NIF_TERM nif_build_schema(ErlNifEnv *env, int argc,
                              const ERL_NIF_TERM argv[])
{

    if (argc < 1)
    {
        return enif_make_badarg(env);
    }

    ERL_NIF_TERM list_head;
    ERL_NIF_TERM list_tail;
    ERL_NIF_TERM active_list = argv[0];

    std::vector<std::shared_ptr<arrow::Field>> fields;

    if (!enif_is_list(env, active_list))
    {
        return make_error(env, "unable to get type list");
    }

    while (enif_get_list_cell(env, active_list, &list_head, &list_tail) == 1)
    {
        int arity = 0;
        const ERL_NIF_TERM *values;
        ERL_NIF_TERM arrow_type;
        std::string name;

        if (enif_get_tuple(env, list_head, &arity, &values) == 0 || arity != 2)
        {
            return make_error(env, "unable to get type tuple");
        }

        if (!get_string(env, values[0], name))
        {
            return make_error(env, "unable to get type name");
        }

        arrow_type = values[1];

        // Build field types
        std::shared_ptr<arrow::DataType> adt;
        IF_TYPE(ATOMS.atomArrowNull, arrow::null())
        ELSE_IF_TYPE(ATOMS.atomArrowBoolean, arrow::boolean())
        ELSE_IF_TYPE(ATOMS.atomArrowInt8, arrow::int8())
        ELSE_IF_TYPE(ATOMS.atomArrowInt16, arrow::int16())
        ELSE_IF_TYPE(ATOMS.atomArrowInt32, arrow::int32())
        ELSE_IF_TYPE(ATOMS.atomArrowInt64, arrow::int64())
        ELSE_IF_TYPE(ATOMS.atomArrowUint8, arrow::uint8())
        ELSE_IF_TYPE(ATOMS.atomArrowUint16, arrow::uint16())
        ELSE_IF_TYPE(ATOMS.atomArrowUint32, arrow::uint32())
        ELSE_IF_TYPE(ATOMS.atomArrowUint64, arrow::uint64())
        ELSE_IF_TYPE(ATOMS.atomArrowFloat16, arrow::float16())
        ELSE_IF_TYPE(ATOMS.atomArrowFloat32, arrow::float32())
        ELSE_IF_TYPE(ATOMS.atomArrowFloat64, arrow::float64())
        ELSE_IF_TYPE(ATOMS.atomArrowUtf8, arrow::utf8())
        ELSE_IF_TYPE(ATOMS.atomArrowLargeUtf8, arrow::large_utf8())
        ELSE_IF_TYPE(ATOMS.atomArrowBinary, arrow::binary())
        ELSE_IF_TYPE(ATOMS.atomArrowLargeBinary, arrow::large_binary())
        else
        { // Invalid arrow type
            return make_error(env, "invalid arrow type");
        }

        fields.push_back(arrow::field(name, adt));
        // Move forward in linked list
        active_list = list_tail;
    }

    return make_ok_tuple(env, create_shared_ptr_resource(env, RESOURCES.arrow_schema, arrow::schema(fields)));
}

ERL_NIF_TERM nif_print_schema(ErlNifEnv *env, int argc,
                              const ERL_NIF_TERM argv[])
{

    if (argc < 1)
    {
        return enif_make_badarg(env);
    }

    std::shared_ptr<arrow::Schema> schema;
    if(!get_shared_ptr_resource(env, RESOURCES.arrow_schema, argv[0], &schema))
        return make_badarg(env);

    auto s = *schema;
    for (auto &&name : s.field_names())
    {
        printf("%s\n", name.c_str());
    }
    return ATOMS.atomOk;
}