#ifndef SRC_NIF_UTILS_H_
#define SRC_NIF_UTILS_H_

#include <string>
#include <memory>
#include "erl_nif.h"
#include "constants.h"

ERL_NIF_TERM make_atom(ErlNifEnv *env, const char *name);
ERL_NIF_TERM make_error(ErlNifEnv *env, const char *error);
ERL_NIF_TERM make_binary(ErlNifEnv *env, const char *buff, size_t length);
ERL_NIF_TERM make_badarg(ErlNifEnv *env);
ERL_NIF_TERM make_bad_options(ErlNifEnv *env, ERL_NIF_TERM term);
ERL_NIF_TERM make_ok_tuple(ErlNifEnv *env, ERL_NIF_TERM term);

bool get_bstring(ErlNifEnv *env, ERL_NIF_TERM term, ErlNifBinary *bin);
bool get_string(ErlNifEnv *env, ERL_NIF_TERM term, std::string &string);

template <typename T>
ERL_NIF_TERM create_shared_ptr_resource(ErlNifEnv *env, ErlNifResourceType *type, std::shared_ptr<T> &&ptr)
{
    ERL_NIF_TERM term;
    std::shared_ptr<T> **obj;

    obj = static_cast<std::shared_ptr<T> **>(enif_alloc_resource(type, sizeof(std::shared_ptr<T> *)));

    *obj = new std::shared_ptr<T>(ptr);

    term = enif_make_resource(env, obj);
    enif_release_resource(obj);

    return term;
}

template <typename T>
bool get_shared_ptr_resource(ErlNifEnv *env, ErlNifResourceType *type, ERL_NIF_TERM r, std::shared_ptr<T> *resource)
{
    std::shared_ptr<T> **ptr = NULL;
    if (!enif_get_resource(env, r, type, reinterpret_cast<void **>(&ptr)))
        return false;

    *resource = **ptr;
    return true;
}

#endif // SRC_NIF_UTILS_H_