#include <czcomplex.h>
int mpc_log(mp_complex * a, mp_complex * b)
{
    int err;
    mp_float aa,bb,t1;

    err = MP_OKAY;

    aa = MPC_REAL(a);
    bb = MPC_REAL(b);

    mpf_init(&t1,MPC_REAL(a).radix);

    if(mpf_iszero(&aa) && mpf_iszero(&aa)){
        mpf_const_nan(&(MPC_REAL(b)));
        mpf_const_nan(&(MPC_IMAG(b)));
        goto _ERR;
    } else if(mpf_iszero(&bb)){
        mpf_abs(&aa,&t1);
        mpf_ln(&t1,&(MPC_REAL(b)));
        if(aa.mantissa.sign == MP_NEG){
            mpf_const_pi(&(MPC_IMAG(b)));
        } else {
            mpf_copy(&aa, &(MPC_IMAG(b)));
        }
        goto _ERR;
    } else {
        mpf_abs(&aa,&t1);
        mpf_ln(&t1,&(MPC_REAL(b)));
        mpf_atan2(&bb,&aa, &(MPC_IMAG(b)));
    }

_ERR:
   mpf_clear(&t1);
   return err;
}
