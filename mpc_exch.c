#include <czcomplex.h>
int mpc_exch(mp_complex * a, mp_complex * b)
{
  mpf_exch(&(MPC_REAL(a)),&(MPC_REAL(b)));
  mpf_exch(&(MPC_IMAG(a)),&(MPC_IMAG(b)));
}
