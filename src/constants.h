#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

#include "erl_nif.h"

struct atoms
{
    ERL_NIF_TERM atomOk;
    ERL_NIF_TERM atomError;
    ERL_NIF_TERM atomTrue;
    ERL_NIF_TERM atomFalse;
    ERL_NIF_TERM atomNull;
    ERL_NIF_TERM atomBadArg;
    ERL_NIF_TERM atomOptions;

    // events atoms

    // data types

    // column types

    // metadata
};

extern atoms ATOMS;

namespace ex_libarrow
{
void setup_atoms(ErlNifEnv *env);
} // namespace ex_libarrow

#endif // SRC_CONSTANTS_H_