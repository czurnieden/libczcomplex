#include <czcomplex.h>
int mpc_set_real_int(int a, mp_complex * b)
{
    int err;
    err = MP_OKAY;

    if ((err = mpf_set_int(a, b->re)) != MP_OKAY) {
        return err;
    }
    return err;
}

