#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kfifo.h>

MODULE_DESCRIPTION("GPL");
MODULE_AUTHOR("Sameer Patil");
MODULE_DESCRIPTION("A Simple Hello World module");

static int test_kfifo(void)
{
	int ret;
	int i, z;
	struct kfifo testbuf;
	ret = kfifo_alloc(&testbuf, sizeof(int) * 8, GFP_KERNEL);
	if (ret)
		printk(KERN_INFO "Failed to buf!");
	for (i = 0; i < 32; i++)
	{
		z = i + 1;
		printk(KERN_INFO "Adding %d\n",z );
		ret = kfifo_in(&testbuf, &z, sizeof(z));
		if (ret)
		{
			printk(KERN_INFO "Cannot add more!\n");
		}
		ret = kfifo_is_full(&testbuf);
		if(ret == 0)
			printk(KERN_INFO "Buffer full for i: %d, ret: %d", (i), ret);
	}
	i = 0;
	ret = kfifo_out_peek(&testbuf, &i, sizeof(i));

	if (ret)
		printk(KERN_INFO "Fot %d\n", i);

	z = kfifo_size(&testbuf);
	printk(KERN_INFO "Size is %d", z);
	while(!kfifo_is_empty(&testbuf))
	{
		ret = kfifo_out(&testbuf, &i, sizeof(i));
		printk(KERN_INFO "Value here %d, ret: %d!\n", i, ret);
	}
	kfifo_free(&testbuf);
	return 0;

}

static int __init helloworld_init(void)
{
	test_kfifo();
	printk(KERN_INFO "Hello World module now running!\n");
	return 0;
}

static void __exit helloworld_exit(void)
{
	printk(KERN_INFO "Module successfully being cleaned up!\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);