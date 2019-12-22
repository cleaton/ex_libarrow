#include <erl_nif.h>

#include "arrow/io/file.h"
#include "parquet/exception.h"
#include "constants.h"
#include "nif_utils.h"

int add (int a, int b)
{
    return a + b;
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

    return 0;
}

ErlNifFunc nif_funcs[] = 
{
    {"add", 2, add_nif},
};

ERL_NIF_INIT(Elixir.ExLibarrow, nif_funcs, on_nif_load, 
    nullptr, nullptr, nullptr);