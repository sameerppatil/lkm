#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kfifo.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sameer Patil");
MODULE_DESCRIPTION("A Simple Hello World module");

static int __init helloworld_init(void)
{
	printk(KERN_INFO "Hello World module now running!\n");
	return 0;
}

static void __exit helloworld_exit(void)
{
	printk(KERN_INFO "Module successfully being cleaned up!\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);
