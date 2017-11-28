#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kfifo.h>

#include "hello_world.h"
#include "common.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sameer Patil");
MODULE_DESCRIPTION("A Simple Hello World module");

static int __init helloworld_init(void)
{
    INFO_PRINT("Hello World module now running!");
    return 0;
}

static void __exit helloworld_exit(void)
{
    INFO_PRINT("Module successfully being cleaned up!");
}

module_init(helloworld_init);
module_exit(helloworld_exit);
