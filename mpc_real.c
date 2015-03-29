#include <czcomplex.h>
int mpc_real(mp_complex * a, mp_complex * b)
{
    int err;
    err = MP_OKAY;
    if ((err = mpf_copy(&(a->re), &(b->re))) != MP_OKAY) {
        return err;
    }
    return err;
}
