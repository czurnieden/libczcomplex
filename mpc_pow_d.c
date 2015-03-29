#include <czcomplex.h>
// TODO: we have a mpc_sqr(), so check if it is really faster and
//       use it to write the common binary power algorithm.
int mpc_pow_d(mp_complex * a, int n, mp_complex * b)
{
   int err;
   mp_complex t1;

   err = MP_OKAY;
   mpc_init(MPC_REAL(a).radix,&t1);

   mpc_set_real_int(n,&t1);
   mpc_pow(a,&t1,b);

_ERR:
   mpc_clear(&t1); 
   return err;
}
