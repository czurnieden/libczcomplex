#include <czcomplex.h>
void mpc_clear_multi(mp_complex * mp, ...)
{
    mp_complex *next_mp = mp;
    va_list args;
    va_start(args, mp);
    while (next_mp != NULL) {
        mpc_clear(next_mp);
        next_mp = va_arg(args, mp_complex *);
    }
    va_end(args);
}
