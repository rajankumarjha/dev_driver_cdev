INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m :=lkmnew.o

lkmnew-objs := s1.o clean.o s1_open.o s1_read.o s1_write.o s1_seek.o  s1_close.o devTrim.o create_scull.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
endif
