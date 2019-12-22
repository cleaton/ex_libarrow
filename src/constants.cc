#include "constants.h"
#include "nif_utils.h"

atoms ATOMS;

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
}

} // namespace ex_libarrow