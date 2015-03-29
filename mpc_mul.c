#include <czcomplex.h>
int mpc_mul(mp_complex * a, mp_complex * b, mp_complex * c)
{
    int err;
    mp_float aa,bb,cc,dd, t1,t2,t3;
 
    err = MP_OKAY;
    mpf_init_multi(MPC_REAL(a).radix,&aa,&bb,&cc,&dd, &t1,&t2,&t3, NULL );

    aa = MPC_REAL(a);
    bb = MPC_IMAG(a);
    cc = MPC_REAL(b);
    dd = MPC_IMAG(b);

    // real part
    mpf_mul(&aa,&cc,&t1);
    mpf_mul(&bb,&dd,&t2);
    mpf_sub(&t1,&t2,&(MPC_REAL(c)));
    // imaginary part
    mpf_mul(&bb,&cc,&t1);
    mpf_mul(&aa,&dd,&t2);
    mpf_add(&t1,&t2,&(MPC_IMAG(c)));

_ERR:
    mpf_clear_multi(&aa,&bb,&cc,&dd, &t1,&t2,&t3, NULL );
    return err;
}
