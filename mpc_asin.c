#include <czcomplex.h>
int mpc_asin(mp_complex * a, mp_complex * b)
{
   int err;
  mp_complex i, negi, one, t1, t2;
  mp_float fone;
  err = MP_OKAY;

  mpc_init_multi(MPC_REAL(a).radix,&i, &negi, &one,&t1,&t2,NULL);
  mpf_init(&fone, MPC_REAL(a).radix);

  mpf_const_d(&fone, 1);
  mpc_set_imag(&fone,&i);
  mpc_set_real(&fone,&one);
  fone.mantissa.sign = MP_NEG;
  mpc_set_imag(&fone,&negi);

  mpc_sqr(a,&t1);
  mpc_sub(&one, &t1, &t1);
  mpc_sqrt(&t1,&t1);

  mpc_mul(a,&i,&t2);
  mpc_add(&t1,&t2,&t2);
  mpc_log(&t2,&t2);

  mpc_mul(&t2,&negi,&t2);

  mpc_exch(&t2,b);

_ERR:
  mpf_clear(&fone);
  mpc_clear_multi(&i, &negi, &one,&t1,&t2,NULL);
   return err;
}
