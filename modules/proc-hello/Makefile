obj-m += proc_hello.o
KDIR = /lib/modules/$(shell uname -r)/build
PWD  = $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

test: proc_hello.ko
	insmod proc_hello.ko
	dmesg | tail -n 1
	sleep 3
	rmmod proc_hello
	dmesg | tail -n 1

.PHONY: all clean test