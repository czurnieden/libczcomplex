#include <czcomplex.h>
int mpc_set_real_mp_int(double a, mp_complex * b)
{
    int err;
    err = MP_OKAY;

    if ((err = mpf_get_double(a, b->im)) != MP_OKAY) {
        return err;
    }
      return err;
}

