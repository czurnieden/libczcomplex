#include <czcomplex.h>
int mpc_set_double(double a, double b, mp_complex * c)
{
    int err;
    err = MP_OKAY;
    if ((err = mpc_set_real_double(a, c)) != MP_OKAY) {
        return err;
    }
    if ((err = mpc_set_imag_double(b, c)) != MP_OKAY) {
        return err;
    }
    return err;
}

