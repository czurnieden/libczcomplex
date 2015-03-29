#include <czcomplex.h>
int mpc_fphase(mp_complex * a, mp_float * b)
{
  return mpf_atan2(&(MPC_REAL(a)), &(MPC_IMAG(a)), b);
}

