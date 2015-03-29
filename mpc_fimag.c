#include <czcomplex.h>
int mpc_fimag(mp_complex * a, mp_float * b)
{
    return mpf_copy(a->im, b);
}

