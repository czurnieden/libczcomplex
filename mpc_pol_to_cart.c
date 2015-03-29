#include <czcomplex.h>
int mpc_pol_to_cart(mp_complex * a, mp_complex * b)
{
    int err;
    mp_float tmp;

    err = MP_OKAY;
    mpf_init(&tmp,MPC_REAL(a).radix);

    mpf_cos(&(MPC_IMAG(a)),&tmp);
    mpf_mul(&(MPC_REAL(a)),&tmp,&(MPC_REAL(b)));

    mpf_sin(&(MPC_IMAG(a)),&tmp);
    mpf_mul(&(MPC_REAL(a)),&tmp,&(MPC_IMAG(b)));

_ERR:
    mpf_clear(&tmp);
    return err;
}
