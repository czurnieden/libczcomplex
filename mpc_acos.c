#include <czcomplex.h>
int mpc_acos(mp_complex * a, mp_complex * b)
{
   int err;
   mp_complex i, pi2, one, t1, t2, t3;
   mp_float tmp;

   mpc_init_multi(MPC_REAL(a).radix,&i, &pi2, &one, &t1, &t2, &t3, NULL );
   mpf_init(&tmp,MPC_REAL(a).radix);

   mpf_const_d(&tmp, 1);
   mpc_set_imag(&tmp, &i);
   mpc_set_real(&tmp, &one);

   mpf_const_pi(&tmp);
   tmp.exp -= 1;
   mpc_set_real(&tmp, &pi2);

   mpc_sqr(a,&t1);
   mpc_sub(&one,&t1,&t1);
   mpc_sqrt(&t1,&t1);

   mpc_mul(a,&i,&t2);
   mpc_add(&t2,&t1,&t2);
   mpc_log(&t2,&t2);

   mpc_mul(&i,&t2,&t2);
   mpc_add(&pi2,&t2,&t2);

   mpc_exch(&t2,b);

_ERR:
   mpf_clear(&tmp);
   mpc_clear_multi(&i, &pi2, &one, &t1, &t2, &t3, NULL );
   return err;
}
