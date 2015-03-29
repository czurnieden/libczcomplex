#include <czcomplex.h>
int mpc_sqrt(mp_complex * a, mp_complex * b)
{
   int err;
   mp_float aa,bb,t1,t2;

   err = MP_OKAY;
   mpf_init_multi(MPC_REAL(a).radix,&t1,&t2,NULL);
   aa = MPC_REAL(a);
   bb = MPC_IMAG(a);

   if(mpf_iszero(&aa) && mpf_iszero(&bb)){
      mpf_const_d(&(MPC_REAL(b)),0);
      mpf_const_d(&(MPC_IMAG(b)),0);
      goto _ERR;
   } else if(mpf_iszero(&bb)){
      if(aa.mantissa.sign == MP_ZPOS){
         mpf_sqrt(&aa,&(MPC_REAL(b)));
         mpf_const_d(&(MPC_IMAG(b)),0);
         goto _ERR;
      } else {
         mpf_const_d(&(MPC_REAL(b)),0);
         mpf_abs(&aa,&t1);
         mpf_sqrt(&t1,&(MPC_IMAG(b)));
         goto _ERR;
      }
   } else {
      if(aa.mantissa.sign == MP_ZPOS){
         mpc_fabs(a,&t1);
         mpf_add(&t1,&aa,&t1);
         t1.exp -= 1;
         mpf_sqrt(&t1,&t1);
         mpf_copy(&t1,&(MPC_REAL(b)));
         t1.exp += 1;
         mpf_div(&bb,&t1,&(MPC_IMAG(b)));
         goto _ERR;
      } else {
         mpc_fabs(a,&t1);
         mpf_sub(&t1,&aa,&t1);
         t1.exp -= 1;
         mpf_sqrt(&t1,&t1);
         if(bb.mantissa.sign == MP_NEG){
           mpf_neg(&t1,&t1);
         }
         mpf_copy(&t1,&(MPC_IMAG(b)));
         t1.exp += 1;
         mpf_div(&bb,&t1,&(MPC_REAL(b)));
         goto _ERR;
      }
   }

_ERR:
    mpf_clear_multi(&t1,&t2,NULL);
    return err;
}

