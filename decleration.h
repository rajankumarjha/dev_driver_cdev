
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
	
	#ifndef DEVICE_SIZE
	#define DEVICE_SIZE 1024
	#endif
	
	#ifndef DATA_SIZE
	#define DATA_SIZE 0
	#endif
	
	#ifndef REGISTER_SIZE
	#define REGISTER_SIZE 4
	#endif

	#ifndef NO_OF_REGISTER
	#define NO_OF_REGISTER 8
	#endif
	
	#ifndef DEVNAME
	#define DEVNAME "CHARACTER_DRIVER"
	#endif
#endif

extern int majorno,minorno,nod;
extern dev_t devid,devno;
extern int device_size,data_size,register_size,no_of_register;
int module(void);
typedef struct qset
{
	struct qset * next;
	void **data;
}qset;
qset* create_scull(size_t);
typedef struct dev
{
struct cdev CDev;
struct qset *first;
int device_size;
int data_size;
int register_size;
int no_of_register;
}Dev;
int devTrim(Dev*);
extern Dev *memory;


int s1_open (struct inode *, struct file *);
loff_t s1_seek (struct file *, loff_t, int);
ssize_t s1_read (struct file *, char __user *, size_t, loff_t *);
ssize_t s1_write (struct file *, const char __user *, size_t, loff_t *);
int s1_close (struct inode *, struct file *);
