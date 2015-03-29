#include <czcomplex.h>
int mpc_set_real(mp_float * a, mp_complex * b)
{
    int err;
    err = MP_OKAY;
    if ((err = mpf_copy(a, &(b->re))) != MP_OKAY) {
	return err;
    }
    return err;
}

