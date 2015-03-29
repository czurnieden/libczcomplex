#include <czcomplex.h>
int mpc_atan2(mp_complex * a, mp_complex * b, mp_complex * c)
{
   int err;
   mp_complex tmp;

   err = MP_OKAY;

   mpc_init(MPC_REAL(a).radix, &tmp);

   mpc_div(a,b,&tmp);
   mpc_atan(&tmp,&tmp);
   mpc_exch(&tmp, c);

_ERR:
   mpc_clear(&tmp);
   return err;
}
