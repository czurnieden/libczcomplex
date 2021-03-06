#include <czcomplex.h>
int mpc_norm(mp_complex * a, mp_complex * b)
{
    int err;
    mp_float t1,t2;

    err = MP_OKAY;
    mpf_init_multi(MPC_REAL(a).radix,&t1,&t2,NULL);

    mpf_sqr(&(MPC_REAL(a)),&t1);
    mpf_sqr(&(MPC_IMAG(a)),&t2);
    mpf_add(&t1,&t2,&t2);
    mpf_exch(&t2,&(MPC_REAL(b)));

_ERR:
    mpf_clear_multi(&t1,&t2,NULL);
    return err;
}
