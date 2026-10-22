obj-m += proc_jiffies.o
KDIR = /lib/modules/$(shell uname -r)/build
PWD  = $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean

test: proc_jiffies.ko
	insmod proc_jiffies.ko
	dmesg | tail -n 1
	sleep 3
	rmmod proc_jiffies
	dmesg | tail -n 1

.PHONY: all clean test