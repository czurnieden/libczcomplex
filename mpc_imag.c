#include <czcomplex.h>
int mpc_imag(mp_complex * a, mp_complex * b)
{
    int err;
    err = MP_OKAY;
    if ((err = mpf_copy(&(a->im), &(b->im))) != MP_OKAY) {
        return err;
    }
    return err;
}
