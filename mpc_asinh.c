#include <czcomplex.h>
int mpc_asinh(mp_complex * a, mp_complex * b)
{
    int err;
    mp_complex one, t1;
    mp_float fone;
    err = MP_OKAY;

    mpc_init_multi(MPC_REAL(a).radix, &one,&t1,NULL);
    mpf_init(&fone, MPC_REAL(a).radix);

    mpf_const_d(&fone,1);
    mpc_set_real(&fone,&one);

    mpc_sqr(a,&t1);
    mpc_add(&one,&t1,&t1);
    mpc_sqrt(&t1,&t1);
    mpc_add(a,&t1,&t1);
    mpc_log(&t1,&t1);

    mpc_exch(&t1,b);

_ERR:
    mpf_clear(&fone);
    mpc_clear_multi(&one,&t1,NULL);
return err;
}
