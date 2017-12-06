#include"header.h"
#include"decleration.h"


int s1_open(struct inode *pinode, struct file *pfile)
{
Dev *ldev;
int ret;
ldev=container_of(pinode->i_cdev,Dev,CDev);
if(!ldev)
{
		printk(KERN_INFO "ldev failed");
}
if((pfile->f_flags & O_ACCMODE)==O_WRONLY)
{
	ret=devTrim(ldev);
	if(ret==-1)
	{
		printk(KERN_INFO "devTrim failed");
	}
}

pfile->private_data=ldev;
printk(KERN_INFO "INSIDE THE %s FUNCTION\n",__func__);
return 0;

}

