#include "header.h"
#include "decleration.h"
#include"fops.h"

int majorno,minorno,nod;
dev_t devid,devno;
int ret,ret2,i;
Dev *memory;
int device_size,data_size,register_size,no_of_register;
//EXPORT_SYMBOL(mysymbol);

static int __init initfunc(void)
{
	majorno=MAJORNO;
	minorno=MINORNO;
	nod=NOD;
//	printk(KERN_INFO "Hello kernel here we are\n");
	//majorno=register_chrdev(majorno,DEVNAME,&fops);
	if(majorno==0)
	{
		ret=alloc_chrdev_region(&devid,minorno,nod,DEVNAME);
		if(ret==-1)
		{
			printk(KERN_ERR"ALLOC NOT WORKING\n");
			goto out;
		}
	}
	else
	{
		ret=register_chrdev_region(devno,nod,DEVNAME);
		if(ret==-1)
		{
			printk(KERN_ERR"Register_dev error\n");
			goto out;
		}
	}

	printk(KERN_INFO "MAJORNO %d \n",MAJOR(devid));
	printk(KERN_INFO "MINORNO %d \n",MINOR(devid));
	majorno=MAJOR(devid);
	memory=(Dev*)kmalloc(sizeof(Dev)*NOD,GFP_KERNEL); 
	memset(memory,'\0',sizeof(memory)*NOD);
	printk(KERN_INFO "memory :=%p\n",memory);
	for(i=0;i<nod;i++)
	{
		cdev_init(&memory[i].CDev,&fops);
		memory[i].CDev.ops=&fops;
		device_size=DEVICE_SIZE;
		data_size=DATA_SIZE;
		register_size=REGISTER_SIZE;
		no_of_register=NO_OF_REGISTER;
		memory[i].device_size=device_size;
		memory[i].data_size=data_size;
		memory[i].register_size=register_size;
		memory[i].no_of_register=no_of_register;
		devno=MKDEV(majorno,i);	
		ret2=cdev_add(&memory[i].CDev,devno,nod);
		if(ret2==-1)
		{
			printk(KERN_ERR"cdev error\n");
			goto out;
		}
		printk(KERN_INFO "ret2--- :%d\n",ret2);
	}
	return 0;

out:
	return -1;


}

module_init(initfunc);
