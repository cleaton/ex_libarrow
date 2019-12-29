#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

#include "erl_nif.h"

#define ATOM_MAX_LENGTH 30

struct atoms
{
    ERL_NIF_TERM atomOk;
    ERL_NIF_TERM atomError;
    ERL_NIF_TERM atomTrue;
    ERL_NIF_TERM atomFalse;
    ERL_NIF_TERM atomNull;
    ERL_NIF_TERM atomBadArg;
    ERL_NIF_TERM atomOptions;

    // arrow types
    ERL_NIF_TERM atomArrowNull;
    ERL_NIF_TERM atomArrowBoolean;
    ERL_NIF_TERM atomArrowInt8;
    ERL_NIF_TERM atomArrowInt16;
    ERL_NIF_TERM atomArrowInt32;
    ERL_NIF_TERM atomArrowInt64;
    ERL_NIF_TERM atomArrowUint8;
    ERL_NIF_TERM atomArrowUint16;
    ERL_NIF_TERM atomArrowUint32;
    ERL_NIF_TERM atomArrowUint64;
    ERL_NIF_TERM atomArrowFloat16;
    ERL_NIF_TERM atomArrowFloat32;
    ERL_NIF_TERM atomArrowFloat64;
    ERL_NIF_TERM atomArrowUtf8;
    ERL_NIF_TERM atomArrowLargeUtf8;
    ERL_NIF_TERM atomArrowBinary;
    ERL_NIF_TERM atomArrowLargeBinary;

    // events atoms

    // data types

    // column types

    // metadata
};

struct resources {
    ErlNifResourceType* arrow_schema;
};

extern resources RESOURCES;

extern atoms ATOMS;

namespace ex_libarrow
{
void setup_atoms(ErlNifEnv *env);
} // namespace ex_libarrow

#endif // SRC_CONSTANTS_H_