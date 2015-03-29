#include <czcomplex.h>
int mpc_set_imag(mp_float * a, mp_complex * b)
{
    int err;
    err = MP_OKAY;
    if ((err = mpf_copy(a, &(b->im))) != MP_OKAY) {
	return err;
    }
    return err;
}
