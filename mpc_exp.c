#include <czcomplex.h>
int mpc_exp(mp_complex * a, mp_complex * b)
{
   int err;
   mp_float aa, bb;
   mp_complex tmp;

   err = MP_OKAY;

   aa = MPC_REAL(a);
   bb = MPC_IMAG(a);

   mpc_init(MPC_REAL(a).radix,&tmp);

   //  exp(real(a)) * (cos(imag(a)) + sin(imag(a)) * I)
   mpf_exp(&aa,&tmp.re);
   mpf_copy(&bb,&tmp.im);
   mpc_pol_to_cart(&tmp,b);

_ERR:
   mpc_clear(&tmp);
   return err;
}
