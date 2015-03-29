#include <czcomplex.h>
int mpc_acosh(mp_complex * a, mp_complex * b)
{
   int err;
   mp_complex one, t1, t2;
   mp_float tmp;

   err = MP_OKAY;

   mpc_init_multi(MPC_REAL(a).radix, &one, &t1, &t2, NULL );
   mpf_init(&tmp, MPC_REAL(a).radix);

   mpf_const_d(&tmp,1);
   mpc_set_real(&tmp, &one);

   mpc_sub(a, &one,&t1);
   mpc_add(a, &one,&t2);

   mpc_mul(&t1,&t2,&t2);
   mpc_add(a,&t2,&t2);
   mpc_log(&t2,&t2);
   
   mpc_exch(&t2,b);
_ERR:
   mpc_clear_multi(&one, &t1, &t2);
  return err;
}
