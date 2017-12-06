#include"header.h"
#include"decleration.h"


loff_t s1_seek (struct file *pfile, loff_t offset, int origin)
{
Dev *ldev;
ldev=(Dev*)pfile->private_data;

printk(KERN_INFO "BEGIN %s FUNCTION\n",__func__);
switch(origin)
{
	case SEEK_SET:
			pfile->f_pos=pfile->f_pos+offset;
			printk(KERN_INFO "Seek_set Cursor position %ld",(long)pfile->f_pos);
			break;

	case SEEK_CUR:
			pfile->f_pos=pfile->f_pos+offset;
			printk(KERN_INFO "Seek_cur Cursor position %ld",(long)pfile->f_pos);
			break;

	case SEEK_END:
			pfile->f_pos=pfile->f_pos+offset;
			printk(KERN_INFO "Seek_End Cursor position %ld",(long)pfile->f_pos);
			break;
}
printk(KERN_INFO "END %s FUNCTION\n",__func__);

return 0;

}

