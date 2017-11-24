#include"header.h"
#include"decleration.h"

ssize_t s1_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
int r;
printk(KERN_INFO "INSIDE THE %s FUNCTION\n",__func__);
r =copy_to_user(buffer,virtual.data,length);
return length;

}

