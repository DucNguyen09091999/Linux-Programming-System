#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>


#define DRIVER_AUTHOR "DucNguyen nguyenchiduc090999@gmail.com"
#define DRIVER_DESC "Hello world kernel module"

struct m_foo_dev {
    dev_t dev_num;
    struct class *m_class;
}mdev;

static int
__init hello_world_init(void){
    // Dynamic allocating device number
    if(alloc_chrdev_region(&mdev.dev_num,0,1,"m-dev") < 0){
        pr_err("Failed to allocate chrdev region\n");
        return -1;
    }
    pr_info("Major = %d, Minor = %d\n",MAJOR(mdev.dev_num),MINOR(mdev.dev_num));



    //Create struct class
    if((mdev.m_class = class_create(THIS_MODULE,"m_class")) == NULL){
        pr_err("Can't create the struct class for my device\n");
        goto rm_device_numb;

    }

    //Creating devices
    if((device_create(mdev.m_class,NULL,mdev.dev_num,NULL,"m-device")) == NULL){
        pr_err("can't create my device\n");
        goto rm_class;
    }

    pr_info("Hello world kernel module\n");
    return 0;

rm_class:
    class_destroy(mdev.m_class);
rm_device_numb:
    unregister_chrdev_region(mdev.dev_num,1);
    return -1;

}

static void
__exit hello_world_exit(void){
    //Unallocating device number
    device_destroy(mdev.m_class,mdev.dev_num); //Destroy device -> class -> allocate
    class_destroy(mdev.m_class);
    unregister_chrdev_region(mdev.dev_num,1);
    pr_info("Goodbye\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);