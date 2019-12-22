#ifndef SRC_NIF_UTILS_H_
#define SRC_NIF_UTILS_H_

#include "erl_nif.h"

ERL_NIF_TERM make_atom(ErlNifEnv* env, const char* name);
ERL_NIF_TERM make_error(ErlNifEnv* env, const char* error);
ERL_NIF_TERM make_binary(ErlNifEnv* env, const char* buff, size_t length);
ERL_NIF_TERM make_badarg(ErlNifEnv* env);
ERL_NIF_TERM make_bad_options(ErlNifEnv* env, ERL_NIF_TERM term);

bool get_bstring(ErlNifEnv* env, ERL_NIF_TERM term, ErlNifBinary* bin);

#endif  // SRC_NIF_UTILS_H_