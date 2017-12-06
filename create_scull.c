#include"header.h"
#include"decleration.h"

qset * create_scull(size_t size1)
{
	int noi,noq,i,p=0;   //noq : no of quamtum set , noi : no of items 
	qset *first=NULL;
	qset *last=NULL;
//	size_t lsize =0;
	printk(KERN_INFO "Create_scull Begin");
	
	noq=size1/register_size; //noq only stores integer value here..
	if(size1%register_size)  //if it have fraction part then increment noq value by 1...
	{
		noq++;
	}

	noi=size1/(no_of_register*register_size);  //noi only have integer value here...
	if(size1%(no_of_register*register_size))  //if it have fraction value then noi value is incremented by 1..
	{
		noi++;
	}
	for(i=0;i<noi;i++)  //Assinging memory for no of items
	{
		if(i==0)
		{
			last=first=(qset*)kmalloc(sizeof(qset),GFP_KERNEL);  //store 1st memory block of noi to first and last pointer...

			memset(last,'\0',sizeof(qset));   //initilize it to zero...
		}
		else
		{
			last->next=(qset*)kmalloc(sizeof(qset),GFP_KERNEL);  //Assigning new memory block to last->next...

			memset(last->next,'\0',sizeof(qset)); //initilizing its value to zero...
			last=last->next;   //giving last pointer the address of last->next....
		}

	}

	last=first;   //now assigning address stored in first pointer variable to last pointer variable.....
	//------------------Finished creating Items/Node--------------------------//
	
	//------------------Start Creating Quantoms------------------------------//

	for(i=0;i<noi;i++)  //here we are allocating memory to quantoms..
	{
	
			last->data=kmalloc(sizeof(char*)*8,GFP_KERNEL);

			memset(last->data,'\0',sizeof(char*)*8);

			last=last->next;

	}
	//------------------END Creating Quantoms------------------------------//
	last=first;

	for(i=0;i<noq;i++) // l
	{
			last->data[p]=kmalloc(sizeof(char)*register_size,GFP_KERNEL);
			memset(last->data,'\0',sizeof(char)*register_size);
			
			if(p==(no_of_register-1))
			{
				last=last->next;
				p=0;
			}
			else
				p++;

	}


return (first);


}
