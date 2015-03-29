#include <czcomplex.h>
int mpc_log_branch(mp_complex * a, int branch, mp_complex * b)
{
    int err;
    mp_complex i, t1, t2;
    mp_float tmp, pi;

   mpf_init_multi(MPC_REAL(a).radix, &tmp,&pi);
   mpc_init_multi(MPC_REAL(a).radix,&i,&t1,&t2,NULL);

   mpc_set_imag_int(1,&i);

   mpf_set_int(&tmp,branch * 2);
   mpf_const_pi(&pi);
   mpf_mul(&tmp,&pi,&(t1.re));
   mpc_mul(&t1,&i,&t1);

   mpc_log(a,&t2);
   mpc_add(&t2,&t1,&t2);

   mpc_exch(&t2,b);

_ERR:
   mpf_clear_multi(&tmp,&pi,NULL);
   mpc_clear_multi(&i,&t1,&t2,NULL);
}
