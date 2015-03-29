#GCC makefile for LibCZComplex

default: libczcomplex.a
CFLAGS += -O2 -g3 -Wall -W -I./

VERSION=0.01

LIBNAME=libczcomplex.a
HEADERS=czcomplex.h

DESTDIR=
LIBPATH=/usr/lib
INCPATH=/usr/include
#DATAPATH=/usr/share/doc/libczcomplex/pdf

OBJECTS = \
mpc_abs.o mpc_acos.o mpc_acosh.o mpc_add.o mpc_arg.o mpc_asin.o mpc_asinh.o\
mpc_atan2.o mpc_atan.o mpc_atanh.o mpc_cart_to_pol.o mpc_clear.o\
mpc_clear_multi.o mpc_cmp.o mpc_conj.o mpc_copy.o mpc_cos.o mpc_cosh.o\
mpc_div.o mpc_exch.o mpc_exp.o mpc_imag.o mpc_init.o mpc_init_multi.o mpc_inv.o\
mpc_lambertw.o mpc_log_branch.o mpc_log.o mpc_mul.o mpc_neg.o mpc_norm.o\
mpc_phase.o mpc_pol_to_cart.o mpc_pow_branch.o mpc_pow.o mpc_pow_d_branch.o\
mpc_pow_d.o mpc_real.o mpc_set.o mpc_set_imag.o mpc_set_real.o mpc_sin.o\
mpc_sinh.o mpc_sqr.o mpc_sqrt_branch.o mpc_sqrt.o mpc_sub.o mpc_tan.o\
mpc_tanh.o

libczcomplex.a: $(OBJECTS)
	$(AR) $(ARFLAGS) libczcomplex.a $(OBJECTS)
	ranlib libczcomplex.a

install: libczcomplex.a
	install -d -g root -o root $(DESTDIR)$(LIBPATH)
	install -d -g root -o root $(DESTDIR)$(INCPATH)
	install -g root -o root $(LIBNAME) $(DESTDIR)$(LIBPATH)
	install -g root -o root $(HEADERS) $(DESTDIR)$(INCPATH)

clean:
	rm -f $(OBJECTS) libczcomplex.a *~

tar: clean
	cd .. ; rm -rf libczcomplex-$(VERSION) ; mkdir libczcomplex-$(VERSION) ; \
	cp -R ./libczcomplex/* ./libczcomplex-$(VERSION)/ ; \
	tar -cjfv libczcomplex_$(VERSION).tar.bz2 libczcomplex-$(VERSION)/*; \
	cd ./libczcomplex/

zip: clean
	cd .. ; rm -rf libczcomplex-$(VERSION) ; mkdir libczcomplex-$(VERSION) ; \
	cp -R ./libczcomplex/* ./libczcomplex-$(VERSION)/ ; \
	zip -9 -r libczcomplex_$(VERSION).zip libczcomplex-$(VERSION)/*; \
	cd ./libczcomplex/

