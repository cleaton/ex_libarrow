#include <erl_nif.h>
#include "constants.h"
#include "nif_utils.h"
#include "arrow_schema.h"

int add (int a, int b)
{
    return a + b;
}

void shared_ptr_dtor(ErlNifEnv* env, void* obj)
{
    std::shared_ptr<void>** data = static_cast<std::shared_ptr<void>**>(obj);
    if (data != NULL && *data != NULL)
        delete *data;
}

void open_resources(ErlNifEnv* env)
{
    ErlNifResourceFlags flags =  static_cast<ErlNifResourceFlags>(ERL_NIF_RT_CREATE | ERL_NIF_RT_TAKEOVER);
    RESOURCES.arrow_schema = enif_open_resource_type(env, NULL, "arrow_schema", shared_ptr_dtor, flags, NULL);
}

ERL_NIF_TERM add_nif(ErlNifEnv* env, int argc, 
    const ERL_NIF_TERM argv[])
{
    int a = 0;
    int b = 0;
    
    if (!enif_get_int(env, argv[0], &a)) {
        return enif_make_badarg(env);
    }
    if (!enif_get_int(env, argv[1], &b)) {
        return enif_make_badarg(env);
    }
    
    int result = add(a, b);
    return enif_make_int(env, result);
}

int on_nif_load(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info)
{

    ex_libarrow::setup_atoms(env);
    open_resources(env);

    return 0;
}

ErlNifFunc nif_funcs[] = 
{
    {"add", 2, add_nif},
    {"build_schema", 1, nif_build_schema},
    {"print_schema", 1, nif_print_schema},
};

ERL_NIF_INIT(Elixir.ExLibarrow, nif_funcs, on_nif_load, 
    nullptr, nullptr, nullptr);