#include <czcomplex.h>
int mpc_set_mp_int(mp_int * a, mp_int * b, mp_complex * c)
{
    int err;
    err = MP_OKAY;
    if ((err = mpc_set_real_mp_int(a, c)) != MP_OKAY) {
        return err;
    }
    if ((err = mpc_set_imag_mp_int(b, c)) != MP_OKAY) {
        return err;
    }
    return err;
}
