obj-m += proc_seconds.o
KDIR = /lib/modules/$(shell uname -r)/build
PWD  = $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

test: proc_seconds.ko
	insmod proc_seconds.ko
	dmesg | tail -n 1
	sleep 3
	rmmod proc_seconds
	dmesg | tail -n 1

.PHONY: all clean test