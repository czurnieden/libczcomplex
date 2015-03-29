#include <czcomplex.h>
int mpc_add(mp_complex * a, mp_complex * b, mp_complex * c)
{
   int err;
   /* b.re = a.re + b.re */
   mpf_add(&(MPC_REAL(a)),&(MPC_REAL(b)), &(MPC_REAL(c)));
   /* b.im = a.im + b.im */
   mpf_add(&(MPC_IMAG(a)),&(MPC_IMAG(b)), &(MPC_IMAG(c)));
}
