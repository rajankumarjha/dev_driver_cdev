#include"header.h"
#include"decleration.h"

ssize_t s1_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	Dev *ldev;
	qset *Qset;
	size_t size1;   // we will use to check how much more we can write..
	int ret,noctw=0,nocsw=0,p=0;
	ldev = pfile->private_data;    //ldev points to pfile->private_data...
	printk(KERN_INFO "WRITE FUNC BEGIN");
	if(length==0) //if 'length' to write is 0 then :
	{
		printk(KERN_INFO "Nothing to write");
		return -1;
	}

	if(length>=ldev->device_size-ldev->data_size)//if 'length' is >= device_size(1024)-data_size(data already writen) then write in remaining.
	{
		printk(KERN_INFO "You have crossed the limit!!");
		noctw=size1=ldev->device_size-ldev->data_size;   //bytes to write in size1...

	}
	else 
	{
		noctw=size1=length;
	}	
	printk(KERN_INFO "Length in Write Fucn--  %ld !!",size1);
	ldev->first=create_scull(size1);  //create_scull function called and ldev->first contain 1st node of created scull...
	Qset=ldev->first;     
	while(noctw)
	{	
		
		if(noctw>register_size)
			noctw=register_size;
		ret=copy_from_user(Qset->data[p],buffer+nocsw,noctw); //copy_from_user macro copy noctw bytes to Qset->data[p] from buffer+nocsw..
	
		nocsw=nocsw+(noctw-ret); //we are counting no of sucessfully written bytes..
		noctw=size1-nocsw;       //Now we can reduce the no of bytes to write(size1) by nocsw... 
		data_size=nocsw;       //data_size i.e no of data alredy writen increases by nocsw....
		if(p==(no_of_register-1))   //checking if this nodes quantom_set is full if yes then shift to next node...
                  {
                        Qset=Qset->next;   //shifting to next node....
                        p=0;
                  }
                else
                    p++;

		
	}

	ldev->data_size=ldev->data_size+nocsw;   //adding nocsw to data_size...
	printk(KERN_INFO "WROTE %d charecters",nocsw);
	printk(KERN_INFO "WRITE FUNC END");
	return length;
}

