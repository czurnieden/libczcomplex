#include <czcomplex.h>
int mpc_sqr(mp_complex * a, mp_complex * b)
{
  int err;
  mp_complex t1,t2,t3;
  mp_float x,y;

  err = MP_OKAY;
  mpf_init_multi(MPC_REAL(a).radix,&x,&y,NULL);
  mpc_init_multi(MPC_REAL(a).radix,&t1,&t2,&t3,NULL);

  mpf_copy(&(MPC_REAL(a)),&x);
  mpf_copy(&(MPC_IMAG(a)),&y);

  /*
     a = x + yi
     a^2 = x^2 + 2xyi - y^2

     b = x - yi
     b^2 = x^2 - 2xyi - y^2
  */

  mpf_sqr(&x,&(t1.re));
  mpf_mul(&x,&y,&(t2.im));
  t2.im.exp += 1;
  mpf_sqr(&y,&(t2.re));
  if(y.mantissa.sign == MP_NEG){
    mpc_sub(&t1,&t2,&t2);
  } else {
    mpc_add(&t1,&t2,&t2);
  }
  mpc_sub(&t2,&t3,&t2);
  mpc_exch(&t2,b);

_ERR:
  mpf_clear_multi(&x,&y,&t1,&t2,&t3,NULL);
  return err;
}
