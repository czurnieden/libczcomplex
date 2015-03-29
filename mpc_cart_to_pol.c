#include <czcomplex.h>
int mpc_cart_to_pol(mp_complex * a, mp_complex * b)
{

   int err;
   mp_complex tmp;
   mp_float aa,bb;

   err = MP_OKAY;
   mpf_init_multi(MPC_REAL(a).radix,&aa,&bb,NULL);
   mpc_init(MPC_REAL(a).radix,&tmp);

   mpf_copy(&(MPC_REAL(a)),&aa);
   mpf_copy(&(MPC_IMAG(a)),&bb);

   mpc_abs(a,&tmp);
   mpf_atan2(&aa,&bb,&aa);
   mpf_exch(&aa, &(tmp.im));
   mpc_exch(&tmp, b);

_ERR:
   mpf_clear_multi(&aa,&bb,NULL);
   mpc_clear(&tmp);
   return err;
}
