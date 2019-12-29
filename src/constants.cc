#include "constants.h"
#include "nif_utils.h"

atoms ATOMS;

resources RESOURCES;

namespace ex_libarrow
{

void setup_atoms(ErlNifEnv *env)
{
    // misc atoms
    ATOMS.atomOk = make_atom(env, "ok");
    ATOMS.atomError = make_atom(env, "error");
    ATOMS.atomTrue = make_atom(env, "true");
    ATOMS.atomFalse = make_atom(env, "false");
    ATOMS.atomNull = make_atom(env, "null");
    ATOMS.atomBadArg = make_atom(env, "badarg");
    ATOMS.atomOptions = make_atom(env, "options");

    // arrow types
    ATOMS.atomArrowNull = make_atom(env, "null");
    ATOMS.atomArrowBoolean = make_atom(env, "boolean");
    ATOMS.atomArrowInt8 = make_atom(env, "int8");
    ATOMS.atomArrowInt16 = make_atom(env, "int16");
    ATOMS.atomArrowInt32 = make_atom(env, "int32");
    ATOMS.atomArrowInt64 = make_atom(env, "int64");
    ATOMS.atomArrowUint8 = make_atom(env, "uint8");
    ATOMS.atomArrowUint16 = make_atom(env, "uint16");
    ATOMS.atomArrowUint32 = make_atom(env, "uint32");
    ATOMS.atomArrowUint64 = make_atom(env, "uint64");
    ATOMS.atomArrowFloat16 = make_atom(env, "float16");
    ATOMS.atomArrowFloat32 = make_atom(env, "float32");
    ATOMS.atomArrowFloat64 = make_atom(env, "float64");
    ATOMS.atomArrowUtf8 = make_atom(env, "utf8");
    ATOMS.atomArrowLargeUtf8 = make_atom(env, "large_utf8");
    ATOMS.atomArrowBinary = make_atom(env, "binary");
    ATOMS.atomArrowLargeBinary = make_atom(env, "large_binary");
}

} // namespace ex_libarrow