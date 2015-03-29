#include <czcomplex.h>
// Branchcut along the negative real axis
int mpc_sqrt_branch(mp_complex * a, int branch, mp_complex * b)
{
  int err;
  mp_complex t1;

  err = MP_OKAY;
  mpc_init(MPC_REAL(a).radix,&t1);

  mpc_sqrt(a,&t1);
  if(branch < 0){
     mpc_neg(&t1,&t1);
  }
  mpc_exch(&t1,b);

_ERR:
     mpc_clear(&t1);
     return err;
}
