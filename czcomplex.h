#ifndef CZ_COMPLEX_H
#   define CZ_COMPLEX_H

#   include <tomfloat.h>
#   include <stdarg.h>

typedef struct {
    mp_float re;
    mp_float im;
} mp_complex;

int mpc_init(long eps, mp_complex * a);
int mpc_init_multi(long eps, mp_complex * mp, ...);
void mpc_clear(mp_complex * a);
void mpc_clear_multi(mp_complex * mp, ...);

/*
   Functions which return a real value have two forms: one puts the result
   in ther real part of a mp_complex, the other puts it in a mp_float. The
   latter is indicated by a leading 'f', e.g.: mpc_norm() uses a mp_complex,
   mp_fnorm() a mp_float,
*/


/* set real part of complex c to the value of the mp_float a and 
   the imaginary part of complex c to the value of the mp_float b */
int mpc_set(mp_float * a, mp_float * b, mp_complex * c);
/* set real part of complex b to the value of the mp_float a */
int mpc_set_real(mp_float * a, mp_complex * b);
/* set imaginary part of complex b to the value of the mp_float a */
int mpc_set_imag(mp_float * a, mp_complex * b);

/* set real part of complex c to the value of the mp_int a and 
   the imaginary part of complex c to the value of the mp_int b */
int mpc_set_mp_int(mp_int * a, mp_int * b, mp_complex * c);
/* set real part of complex b to the value of the mp_int a */
int mpc_set_real_mp_int(mp_int * a, mp_complex * b);
/* set imaginary part of complex b to the value of the mp_int a */
int mpc_set_imag_mp_int(mp_int * a, mp_complex * b);

/* set real part of complex c to the value of the int a and 
   the imaginary part of complex c to the value of the int b */
int mpc_set_int(int a, int b, mp_complex * c);
/* set real part of complex b to the value of the int a */
int mpc_set_real_int(int a, mp_complex * b);
/* set imaginary part of complex b to the value of the int a */
int mpc_set_imag_int(int a, mp_complex * b);

/* set real part of complex c to the value of the double a and 
   the imaginary part of complex c to the value of the double b */
int mpc_set_double(double a, double b, mp_complex * c);
/* set real part of complex b to the value of the double a */
int mpc_set_real_double(double a, mp_complex * b);
/* set imaginary part of complex b to the value of the double a */
int mpc_set_imag_double(double a, mp_complex * b);



/* Zero out the imaginary part */
int mpc_real(mp_complex * a, mp_complex * b);
int mpc_freal(mp_complex * a, mp_float * b);
/* Zero out the real part */
int mpc_imag(mp_complex * a, mp_complex * b);
int mpc_fimag(mp_complex * a, mp_float * b);
/* 
    Get the innards

    Difference to mpc_fimag()/mpc_freal()?
    The functions work on copy, the macros are just for legibility
 */
#   define MPC_REAL(a) (a->re)
#   define MPC_IMAG(a) (a->im)

/* Deep copy: copy a into b */
int mpc_copy(mp_complex * a, mp_complex * b);
/* Shallow copy (just pointer exchange) */
int mpc_exch(mp_complex * a, mp_complex * b);

/* Norm */
int mpc_norm(mp_complex * a, mp_complex * b);
int mpc_fnorm(mp_complex * a, mp_float * b);
/* Absolute value (magnitude) */
int mpc_abs(mp_complex * a, mp_complex * b);
int mpc_fabs(mp_complex * a, mp_float * b);
/* Phase */
int mpc_phase(mp_complex * a, mp_complex * b);
int mpc_fphase(mp_complex * a, mp_float * b);
/* Negation */
int mpc_neg(mp_complex * a, mp_complex * b);
/* Conjugate */
int mpc_conj(mp_complex * a, mp_complex * b);
/* Multiplicative inverse */
int mpc_inv(mp_complex * a, mp_complex * b);
/* Argument */
int mpc_arg(mp_complex * a, mp_complex * b);
int mpc_farg(mp_complex * a, mp_float * b);

/* Cartesian to polar representation */
int mpc_cart_to_pol(mp_complex * a, mp_complex * b);
/* Polar to Cartesian representation */
int mpc_pol_to_cart(mp_complex * a, mp_complex * b);


/* Comparing returns the same values as the similarily named functions in
   libtommath and libtomfloat with the restrictions regarding the comparing
   of two complex numbers. See source for a more detailed explanation but in
   short: compares for equality first (a.re == b.re && a.im == b.im) then
   the magnitudes and finally the phase angels. Yes, it is costly. */
int mpc_cmp(mp_complex * a, mp_complex * b);
#   define mpc_zero(a) (mpf_zero(a->re) && mpf_zero(a->im))
#   define mpc_isreal(a) (mpf_zero(a->im))
#   define mpc_isimag(a) (mpf_zero(a->re))

/* Basic functions */
int mpc_add(mp_complex * a, mp_complex * b, mp_complex * c);
/*
   TODO: useful?

int mpc_fadd(mp_complex * a, mp_float * real, mp_float * imag, mp_complex * c);
int mpc_add_d(mp_complex * a, double real, double imag, mp_complex * c);

*/
int mpc_sub(mp_complex * a, mp_complex * b, mp_complex * c);
int mpc_mul(mp_complex * a, mp_complex * b, mp_complex * c);
int mpc_sqr(mp_complex * a, mp_complex * b);
int mpc_div(mp_complex * a, mp_complex * b, mp_complex * c);

/* Not so basic functions, principal branch */
int mpc_sqrt(mp_complex * a, mp_complex * b);
int mpc_log(mp_complex * a, mp_complex * b);
int mpc_exp(mp_complex * a, mp_complex * b);
int mpc_pow(mp_complex * a, mp_complex * b, mp_complex * c);
int mpc_pow_d(mp_complex * a, int n, mp_complex * b);
/* Not so basic functions, free choice of branch */
int mpc_sqrt_branch(mp_complex * a, int branch, mp_complex * b);
int mpc_log_branch(mp_complex * a, int branch, mp_complex * b);
int mpc_pow_branch(mp_complex * a, mp_complex * b, int branch, mp_complex * c);
int mpc_pow_d_branch(mp_complex * a, int n, int branch, mp_complex * b);

/* Trigonometrics */

/* Sine and relatives */
int mpc_sin(mp_complex * a, mp_complex * b);
int mpc_sinh(mp_complex * a, mp_complex * b);
int mpc_asin(mp_complex * a, mp_complex * b);
int mpc_asinh(mp_complex * a, mp_complex * b);
/* Cosine and relatives */
int mpc_cos(mp_complex * a, mp_complex * b);
int mpc_cosh(mp_complex * a, mp_complex * b);
int mpc_acos(mp_complex * a, mp_complex * b);
int mpc_acosh(mp_complex * a, mp_complex * b);
/* Tangent and relatives */
int mpc_tan(mp_complex * a, mp_complex * b);
int mpc_tanh(mp_complex * a, mp_complex * b);
int mpc_atan(mp_complex * a, mp_complex * b);
int mpc_atanh(mp_complex * a, mp_complex * b);

int mpc_atan2(mp_complex * a, mp_complex * b, mp_complex * c);

/* Lambert-W (product-log) */
int mpc_lambertw(mp_complex * a, int branch, mp_complex * b);

/* I/O */
/* mp_complex to string of the form  "real +/- imag"+"i" */
int mpc_get_str(mp_complex * a, char **str, int base);
/* 
    sets mp_complex from string of the form  "real +/- imag"+"i"
    Numebr of possible bases might be restricted, please check the source.
 */
int mpc_set_str(const char *str, mp_complex * c);

/*
   TODO: are one or more of the following usefull?

int mpc_round(mp_complex * a, mp_complex * b);

*/

#endif

