#include <czcomplex.h>
/* Shamelessly stolen from Libtommath */
int mpc_init_multi(long eps, mp_complex * mp, ...)
{
    mp_err res = MP_OKAY;
    int n = 0;
    mp_complex *cur_arg = mp;
    va_list args;

    va_start(args, mp);
    while (cur_arg != NULL) {
	if (mpc_init(eps, cur_arg) != MP_OKAY) {
	    va_list clean_args;
	    va_end(args);
	    cur_arg = mp;
	    va_start(clean_args, mp);
	    while (n--) {
		mpc_clear(cur_arg);
		cur_arg = va_arg(clean_args, mp_complex *);
	    }
	    va_end(clean_args);
	    res = MP_MEM;
	    break;
	}
	n++;
	cur_arg = va_arg(args, mp_complex *);
    }
    va_end(args);
    return res;
}

