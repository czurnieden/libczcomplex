#include <czcomplex.h>
int mpc_atanh(mp_complex * a, mp_complex * b)
{

    int err;
    mp_complex one, half, t1, t2;
    mp_float fone;

    err = MP_OKAY;
   mpc_init_multi(MPC_REAL(a).radix, &one, &half, &t1,&t2,NULL);
   mpf_init(&fone,MPC_REAL(a).radix);

   mpf_const_d(&fone,1);
   mpc_set_real(&fone, &one);
   fone.exp -= 1;
   mpc_set_real(&fone, &half);

   mpc_sub(&one,a,&t1);
   mpc_log(&t1,&t1);
   mpc_add(&one,a,&t2);
   mpc_log(&t2,&t2);

   mpc_sub(&t2,&t1,&t1);
   mpc_mul(&half,&t1, &t1);
   mpc_exch(&t1,b);
    
_ERR:
   mpf_clear(&fone);
   mpc_clear_multi(&one, &half, &t1,&t2, NULL);
   return err;
}
