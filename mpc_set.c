#include <czcomplex.h>
int mpc_set(mp_float * a, mp_float * b, mp_complex * c)
{
    int err;
    err = MP_OKAY;
    if ((err = mpc_set_real(a, c)) != MP_OKAY) {
	return err;
    }
    if ((err = mpc_set_imag(b, c)) != MP_OKAY) {
	return err;
    }
    return err;
}

