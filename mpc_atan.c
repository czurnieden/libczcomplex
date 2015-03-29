#include <czcomplex.h>
int mpc_atan(mp_complex * a, mp_complex * b)
{

   int err;
   mp_complex i, i2, one, t1, t2;
   mp_float fone;

   err = MP_OKAY;
   mpc_init_multi(MPC_REAL(a).radix, &i, &i2, &one, &t1,&t2,NULL);
   mpf_init(&fone,MPC_REAL(a).radix);

   mpf_const_d(&fone, 1);

   mpc_set_real(&fone, &one);
   mpc_set_imag(&fone, &i);
   fone.exp -= 1;
   mpc_set_imag(&fone, &i2); 

   mpc_mul(&i,a,&t1);
   mpc_sub(&one,&t1,&t1);
   mpc_add(&one,&t1,&t2);
   mpc_log(&t1,&t1);
   mpc_log(&t2,&t2);

   mpc_sub(&t1,&t2,&t1);
   mpc_mul(&i2,&t1,&t1);

   mpc_exch(&t1,b);

_ERR:
   mpf_clear(&fone);
   mpc_clear_multi(&i, &i2, &one, &t1,&t2, NULL);
   return err;
}
