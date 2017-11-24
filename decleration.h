#ifndef _HEADERS
#define _HEADERS
	
	#ifndef MAJORNO
	#define MAJORNO 0
	#endif
	
	#ifndef MINORNO
	#define MINORNO 0
	#endif
	
	#ifndef NOD
	#define NOD 1
	#endif
	
	#ifndef DEVNAME
	#define DEVNAME "CHARACTER_DRIVER"
	#endif
#endif

extern int majorno,minorno,nod;
extern dev_t devid,devno;
int module(void);

typedef struct fake_device
{
char data[100];
}vir;

extern vir virtual;

typedef struct dev
{
struct cdev CDev;
}Dev;

extern Dev *memory;

int s1_open (struct inode *, struct file *);
//loff_t s1_seek (struct file *, loff_t, int);
ssize_t s1_read (struct file *, char __user *, size_t, loff_t *);
ssize_t s1_write (struct file *, const char __user *, size_t, loff_t *);
int s1_close (struct inode *, struct file *);
