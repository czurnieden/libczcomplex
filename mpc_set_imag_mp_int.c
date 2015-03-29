#include <czcomplex.h>
int mpc_set_real_mp_int(mp_int * a, mp_complex * b)
{
    int err;
    err = MP_OKAY;

    if ((err = mpf_from_mp_int(a, b->im)) != MP_OKAY) {
        return err;
    }
    return err;
}
