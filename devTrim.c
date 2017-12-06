#include "header.h"
#include "decleration.h"

int devTrim(Dev *ldev)
{
	#ifdef DEBUG
	printk(KERN_INFO "DEVTRIM BEGIN");
	#endif
	if(!ldev)
	{
		printk(KERN_INFO "Error");
		goto out;
	}
	if(!ldev->first)
	{
		printk(KERN_INFO "Noting To Trim");
		goto out;
	}
	
	return 0;

out:
	return -1;
}
