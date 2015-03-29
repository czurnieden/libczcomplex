#include <czcomplex.h>
int mpc_freal(mp_complex * a, mp_float * b)
{
    return mpf_copy(a->re, b);

}

