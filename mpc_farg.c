#include <czcomplex.h>
int mpc_farg(mp_complex * a, mp_float * b)
{
   int err;
   mp_float aa,bb, tmp, pi;

   aa = MPC_REAL(a);
   bb = MPC_IMAG(a);
   mpf_init_multi(MPC_REAL(a).radix, &tmp, &pi, NULL);

    if(aa.mantissa.sign == MP_ZPOS){
        mpf_div(&bb,&aa,&tmp);
        mpf_atan(&tmp,&tmp);
        mpf_exch(&tmp, b);
        goto _ERR;
    }
    if(aa.mantissa.sign == MP_NEG && bb.mantissa.sign != MP_NEG){
        mpf_div(&bb,&aa,&tmp);
        mpf_atan(&tmp,&tmp);
        mpf_const_pi(&pi);
        mpf_add(&tmp,&pi,&tmp);
        mpf_exch(&tmp, b);
        goto _ERR;
    }
    if(aa.mantissa.sign == MP_NEG && bb.mantissa.sign == MP_NEG){
        mpf_div(&bb,&aa,&tmp);
        mpf_atan(&tmp,&tmp);
        mpf_const_pi(&pi);
        mpf_sub(&tmp,&pi,&tmp);
        mpf_exch(&tmp, b);
        goto _ERR;
    }
    if(mpf_iszero(&aa) && bb.mantissa.sign == MP_ZPOS){
        mpf_const_pi(&pi);
        pi.exp -= 1;
        mpf_exch(&pi, b);
        goto _ERR;
    }
    if(mpf_iszero(&aa) && bb.mantissa.sign == MP_NEG){
        mpf_const_pi(&pi);
        pi.exp -= 1;
        pi.mantissa.sign = MP_NEG;
        mpf_exch(&pi, b);
        goto _ERR;
    }
    mpf_const_nan(b);
_ERR:
   mpf_clear_multi(&tmp, &pi, NULL);
   return err;

}

