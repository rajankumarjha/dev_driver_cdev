#include"header.h"
#include"decleration.h"

ssize_t s1_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
int r1;
printk(KERN_INFO "INSIDE THE %s FUNCTION\n",__func__);
r1=copy_from_user(virtual.data,buffer,length);
return length;

}

