#include <czcomplex.h>
int mpc_init(long eps, mp_complex * a)
{
    int e;
    if ((e = mpf_init_multi(eps, &a->re, &a->im, NULL)) != MP_OKAY) {
	return e;
    }
    return MP_OKAY;
}

