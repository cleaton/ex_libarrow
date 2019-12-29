#ifndef SRC_ARROW_SCHEMA_H_
#define SRC_ARROW_SCHEMA_H_

#include "erl_nif.h"

ERL_NIF_TERM nif_build_schema(ErlNifEnv *env, int argc,
                              const ERL_NIF_TERM argv[]);

ERL_NIF_TERM nif_print_schema(ErlNifEnv *env, int argc,
                              const ERL_NIF_TERM argv[]);

#endif // SRC_ARROW_SCHEMA_H_