#include <czcomplex.h>
int mpc_conj(mp_complex * a, mp_complex * b)
{
    int err;
    err = MP_OKAY;
    if ((err = mpc_copy(a, b)) != MP_OKAY) {
	return err;
    }
    MPC_IMAG(b).mantissa.sign =
	(MPC_IMAG(b).mantissa.sign == MP_NEG) ? MP_ZPOS : MP_NEG;
    return err;
}

