#include <czcomplex.h>
int mpc_tanh(mp_complex * a, mp_complex * b)
{
  int err;
  mp_complex t1,t2;

  err = MP_OKAY;
  mpc_init_multi(MPC_REAL(a).radix,&t1,&t2,NULL);

  mpc_sinh(a,&t1);
  mpc_cosh(a,&t2);
  mpc_div(&t1,&t2, b);

_ERR:
  mpc_clear_multi(&t1,&t2,NULL);
  return err;
}
