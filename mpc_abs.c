#include <czcomplex.h>
int mpc_abs(mp_complex * a, mp_complex * b)
{
    int err;
    mp_complex t1;

    if (mpf_iszero(&MPC_REAL(a))) {
	if ((err = mpf_abs(&MPC_IMAG(a), &MPC_IMAG(b))) != MP_OKAY) {
	    return err;
	}
	if ((err = mpf_const_d(&MPC_IMAG(b), 0)) != MP_OKAY) {
	    return err;
	}
    }

    if (mpf_iszero(&MPC_IMAG(a))) {
	if ((err = mpf_abs(&MPC_REAL(a), &MPC_REAL(b))) != MP_OKAY) {
	    return err;
	}
	if ((err = mpf_const_d(&MPC_REAL(b), 0)) != MP_OKAY) {
	    return err;
	}
    }

    if (mpf_iszero(&MPC_REAL(a)) && mpf_iszero(&MPC_IMAG(a))) {
	if ((err = mpf_const_d(&MPC_REAL(b), 0)) != MP_OKAY) {
	    return err;
	}
	if ((err = mpf_const_d(&MPC_IMAG(b), 0)) != MP_OKAY) {
	    return err;
	}
    }

    if ((err = mpc_init(MPC_REAL(a).radix, &t1)) != MP_OKAY) {
	return err;
    }
    err = MP_OKAY;
    if ((err = mpc_norm(a, &t1)) != MP_OKAY) {
	goto _ERR;
    }
    if ((err = mpc_sqrt(&t1, &t1)) != MP_OKAY) {
	goto _ERR;
    }
    mpc_exch(&t1, b);

  _ERR:
    mpc_clear(&t1);
    return MP_OKAY;
}

