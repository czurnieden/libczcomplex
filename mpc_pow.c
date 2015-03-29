#include <czcomplex.h>
int mpc_pow(mp_complex * a, mp_complex * b, mp_complex * c)
{
   int err;
   mp_complex t1;

   err = MP_OKAY;
   mpc_init(MPC_REAL(a).radix,&t1); 

   mpc_log(a,&t1);
   mpc_mul(&t1,b,&t1);
   mpc_exp(&t1,c);

_ERR:
   mpc_clear(&t1); 
   return err;
}
