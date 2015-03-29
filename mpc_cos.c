#include <czcomplex.h>
int mpc_cos(mp_complex * a, mp_complex * b)
{
  int err;

  mp_float aa,bb,t1, t2, t3;
  mpf_init_multi(MPC_REAL(a).radix, &aa,&bb,&t1,&t2,&t3,NULL);

  mpf_copy(&(MPC_REAL(a)),&aa);
  mpf_copy(&(MPC_IMAG(a)),&bb);

  mpf_cos(&aa,&t1);
  mpf_cosh(&bb,&t2);
  mpf_mul(&t1,&t2,&t1);

  mpf_sin(&aa,&t2);
  mpf_neg(&t2,&t2);
  mpf_sinh(&bb,&t3);
  mpf_mul(&t2,&t3,&t2);

  mpf_exch(&t1,&(MPC_REAL(b)));
  mpf_exch(&t2,&(MPC_IMAG(b)));

_ERR:
  mpf_clear_multi(&aa,&bb,&t1,&t2,&t3,NULL);
  return err;
}
