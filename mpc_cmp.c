#include <czcomplex.h>
#include <limits.h>

int mpc_cmp(mp_complex * a, mp_complex * b)
{
   int err, cmp_re, cmp_im, cmp_mag;
   mp_complex mag1, mag2;
   mp_float phase1, phase2;


   cmp_re = mpf_cmp(&(MPC_REAL(a)),&(MPC_REAL(b)));
   cmp_im = mpf_cmp(&(MPC_IMAG(a)),&(MPC_IMAG(b)));

    if (cmp_re == MP_EQ && cmp_im == MP_EQ) {
        return MP_EQ;
    }
    // in case of an error in the initialization of the temporary variables
    cmp_mag = INT_MIN;

    mpc_init_multi(MPC_REAL(a).radix, &mag1, &mag2, NULL);
    mpf_init_multi(MPC_REAL(a).radix, &phase1, &phase2, NULL);

    mpc_abs(a,&mag1);
    mpc_abs(b,&mag2);

    cmp_mag = mpf_cmp(&mag1.re, &mag2.re);
    if(cmp_mag == MP_EQ){
       mpf_atan2(&(MPC_REAL(a)), &(MPC_IMAG(a)), &phase1);
       mpf_atan2(&(MPC_REAL(b)), &(MPC_IMAG(b)), &phase2);
       cmp_mag = mpf_cmp(&phase1,&phase2);
    }

_ERR:
    mpf_clear_multi(&phase1, &phase2, NULL);
    mpc_clear_multi(&mag1, &mag2, NULL);
    return cmp_mag;
}
