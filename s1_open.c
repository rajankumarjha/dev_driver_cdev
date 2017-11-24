#include"header.h"
#include"decleration.h"

int s1_open(struct inode *pinode, struct file *pfile)
{
printk(KERN_INFO "INSIDE THE %s FUNCTION\n",__func__);
return 0;

}

