#include <czcomplex.h>
int mpc_phase(mp_complex * a, mp_complex * b)
{
  return mpf_atan2(&(MPC_REAL(a)), &(MPC_IMAG(a)), &(MPC_REAL(b)));

}
