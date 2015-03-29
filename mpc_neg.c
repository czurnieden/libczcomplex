#include <czcomplex.h>
int mpc_neg(mp_complex * a, mp_complex * b)
{
    int err;
    err = MP_OKAY;
    if ((err = mpf_neg(&(MPC_REAL(a)), &(MPC_REAL(b)))) != MP_OKAY) {
	return err;
    }
    if ((err = mpf_neg(&(MPC_IMAG(a)), &(MPC_IMAG(b)))) != MP_OKAY) {
	return err;
    }
    return err;
}

