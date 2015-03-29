#include <czcomplex.h>
int mpc_sub(mp_complex * a, mp_complex * b, mp_complex * c)
{
   int err;
   err = MP_OKAY;
   /* b.re = a.re - b.re */
   mpf_sub(&(MPC_REAL(a)),&(MPC_REAL(b)), &(MPC_REAL(c)));
   /* b.im = a.im - b.im */
   mpf_sub(&(MPC_IMAG(a)),&(MPC_IMAG(b)), &(MPC_IMAG(c)));
   return err;
}
