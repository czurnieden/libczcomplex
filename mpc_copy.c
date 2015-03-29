#include <czcomplex.h>
int mpc_copy(mp_complex * a, mp_complex * b)
{
    int err;
    err = MP_OKAY;

    // TODO: use a temporary variable instead?
    if ((err = mpf_copy(&(MPC_REAL(a)), &(MPC_REAL(b)))) != MP_OKAY) {
	return err;
    }
    if ((err = mpf_copy(&(MPC_IMAG(a)), &(MPC_IMAG(b)))) != MP_OKAY) {
	return err;
    }

    return err;
}

