#ifndef MODULE_COMMON_H
#define MODULE_COMMON_H

#define INFO_PRINT(fmt, args...) printk(KERN_INFO DRIVER_NAME ": %s(): " fmt "\n", __func__, ## args)
#define ERROR_PRINT(fmt, args...) printk(KERN_ERR DRIVER_NAME ": %s(): " fmt "\n", __func__, ## args)

#define CHECK_ERROR(x, y)                                   \
    if ((x))                                                \
    {                                                       \
        ERROR_PRINT(y);                                     \
        return -1;                                          \
    }

#define CHECK_NULL(x, y)                                    \
    if (x == NULL)                                          \
    {                                                       \
        ERROR_PRINT(y);                                     \
        return -1;                                          \
    }

#endif