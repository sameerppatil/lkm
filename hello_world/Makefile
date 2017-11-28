CONFIG_MODULE_SIG=n
obj-m += hello.o
hello-y := src/module_main.o

ccflags-y := -I$(src)/../include
ccflags-y += -I$(src)/include

all: module

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

install:
	insmod hello.ko

uninstall:
	rmmod hello.ko