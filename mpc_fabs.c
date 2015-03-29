#include <czcomplex.h>
int mpc_fabs(mp_complex * a, mp_float * b)
{
    int err;
    mp_float t1;

    if (mpf_iszero(&MPC_REAL(a))) {
        return mpf_abs(&MPC_IMAG(a), b);
    }
    if (mpf_iszero(&MPC_IMAG(a))) {
        return mpf_abs(&MPC_REAL(a), b);
    }
    // TODO: respect sign?
    if (mpf_iszero(&MPC_REAL(a)) && mpf_iszero(&MPC_IMAG(a))) {
        return mpf_const_d(b, 0);
    }

    if ((err = mpf_init(&t1, MPC_REAL(a).radix)) != MP_OKAY) {
        return err;
    }
    err = MP_OKAY;
    if ((err = mpc_fnorm(a, &t1)) != MP_OKAY) {
        goto _ERR;
    }
    if ((err = mpf_sqrt(&t1, &t1)) != MP_OKAY) {
        goto _ERR;
    }
    mpc_exch(&t1, b);

  _ERR:
    mpc_clear(&t1);
    return MP_OKAY;
}

