#include <czcomplex.h>
int mpc_inv(mp_complex * a, mp_complex * b)
{
   int err;
   mp_float aa,bb,c,t1,t2;

   err = MP_OKAY;
   mpf_init_multi(MPC_REAL(a).radix,&aa,&bb,&c,&t1,&t2,NULL);

   mpf_copy(&(MPC_REAL(a)), &aa);
   mpf_copy(&(MPC_IMAG(a)), &bb);
   mpc_fabs(a,&c);

   mpf_sqr(&c,&c);
   mpf_div(&aa,&c,&t1);
   bb.mantissa.sign = (bb.mantissa.sign == MP_NEG)?MP_ZPOS:MP_NEG;
   mpf_div(&bb,&c,&t2);
   mpf_exch(&t1,&(MPC_REAL(b)));
   mpf_exch(&t2,&(MPC_IMAG(b)));

_ERR:
   mpf_clear_multi(&aa,&bb,&c,&t1,&t2,NULL);
   return err;
}
