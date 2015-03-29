#include <czcomplex.h>
int mpc_set_int(int a, int b, mp_complex * c)
{
    int err;
    err = MP_OKAY;
    if ((err = mpc_set_real_int(a, c)) != MP_OKAY) {
        return err;
    }
    if ((err = mpc_set_imag_int(b, c)) != MP_OKAY) {
        return err;
    }
    return err;
}
