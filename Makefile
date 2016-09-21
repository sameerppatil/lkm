CONFIG_MODULE_SIG=n
obj-m += hello.o
hello-y := src/hello_world.o

all: module

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean