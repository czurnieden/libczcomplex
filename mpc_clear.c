#include <czcomplex.h>
void mpc_clear(mp_complex * a)
{
    mpf_clear_multi(&a->re, &a->im, NULL);
}
