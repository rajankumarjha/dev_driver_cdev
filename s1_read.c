#include"header.h"
#include"decleration.h"

ssize_t s1_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	Dev *ldev;
	qset *Qset;
	size_t size1;
	int ret,noctr=0,nocsr=0,p=0;
	ldev = pfile->private_data;    //ldev points to pfile->private_data...
	printk(KERN_INFO "INSIDE THE READ FUNCTION");
	if(length==0)  //Length of characters to read..
	{
		printk(KERN_INFO "Nothing to Read");
		return -1;
	}

	if(length>=ldev->data_size)  //checking if length is >= existing data(ldev->data_size)
	{
		printk(KERN_INFO "You have crossed the limit to read!!");
		noctr=size1=ldev->data_size;  //

	}
	else
	{
		noctr=size1=length;
	}
	Qset=ldev->first;   //fetching first node address into Qset..
	while(noctr) //while no_of_character_to_read(noctr) exists.. loop runs...
	{
		if(noctr>register_size)
			noctr=register_size;
		ret=copy_to_user(buffer+nocsr,Qset->data[p],noctr);  //copy_to_user macro copy data from Qset->data[p] to buffer+nocsr...

		nocsr=nocsr+(noctr-ret);   //Now add no_of_character_successfully_read ...
		noctr=size1-nocsr;    //Now reduce no_of_character_to_read by no of character sucessfully read...
		if(p==(no_of_register-1))  //if one Node is completely read shift to next node...
		{     
			Qset=Qset->next;    //shifting on next node....
			p=0;
		}
		else
			p++;

	}
	printk(KERN_INFO "END READ  FUNCTION");
	return (nocsr);   //return no of character successfully read...

}

