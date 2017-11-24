#include"header.h"
#include"decleration.h"


static void __exit clean(void)
{
	int i;
	for(i=0;i<nod;i++)
	{
	cdev_del(&memory[i].CDev);
	}
	kfree(memory);
	//unregister_chrdev(majorno,DEVNAME);
	unregister_chrdev_region(devid,nod);
	printk(KERN_INFO "BYE KERNEL\n");
}
module_exit(clean);
