#include <czcomplex.h>
// D. Knuth
int mpc_div(mp_complex * a, mp_complex * b, mp_complex * c)
{
  int err, cmp;
  mp_float aa,bb,cc,dd,t1,t2,t3;
  err = MP_OKAY;
  mpf_init_multi(MPC_REAL(a).radix, &aa,&bb,&cc,&dd,&t1,&t2,&t3,NULL);

  aa = MPC_REAL(a);
  bb = MPC_IMAG(a);
  cc = MPC_REAL(b);
  dd = MPC_IMAG(b);

    if (mpf_zero(&aa) && mpf_zero(&aa)) {
        if ((err = mpf_const_d(&MPC_REAL(c), 0)) != MP_OKAY) {
            return err;
        }
        if ((err = mpf_const_d(&MPC_IMAG(c), 0)) != MP_OKAY) {
           return err;
        }
    }
    // IEEE-754
    if (mpf_zero(&cc) && mpf_zero(&dd)) {
        if ((err = mpf_const_inf(&MPC_REAL(c), 0)) != MP_OKAY) {
            return err;
        }
        if ((err = mpf_const_inf(&MPC_IMAG(c), 0)) != MP_OKAY) {
           return err;
        }
    }

    mpf_init_multi(MPC_REAL(a).radix, &t1, &t2, &t3, NULL);
    
    mpf_abs(&cc,&t1);
    mpf_abs(&dd,&t2);
    cmp = mpf_cmp(&t1,&t2);

    if (cmp != MP_LT) {
        mpf_div(&dd,&cc,&t1);

        mpf_mul(&dd,&t1,&t2);
        mpf_add(&cc,&t2,&t2);
        mpf_inv(&t2,&t2);

        // real part
        mpf_mul(&bb,&t1,&t3);
        mpf_add(&aa,&t3,&t3);
        mpf_mul(&t2,&t3,&(MPC_REAL(c)));
        // imaginary part
        mpf_mul(&aa,&t1,&t3);
        mpf_add(&bb,&t3,&t3);
        mpf_mul(&t2,&t3,&(MPC_IMAG(c)));

    } else {
        mpf_div(&cc,&dd,&t1);

        mpf_mul(&cc,&t1,&t2);
        mpf_add(&dd,&t2,&t2);
        mpf_inv(&t2,&t2);

        // real part
        mpf_mul(&aa,&t1,&t3);
        mpf_add(&bb,&t3,&t3);
        mpf_mul(&t2,&t3,&(MPC_REAL(c)));
        // imaginary part
        mpf_mul(&bb,&t1,&t3);
        mpf_sub(&t3,&aa,&t3);
        mpf_mul(&t2,&t3,&(MPC_IMAG(c)));
    }

_ERR:
    mpf_clear_multi(&t1, &t2, &t3, NULL);
  return err;
}
