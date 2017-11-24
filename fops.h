//int s1_open (struct inode *, struct file *);
//loff_t s1_seek (struct file *, loff_t, int);
//ssize_t s1_read (struct file *, char __user *, size_t, loff_t *);
//ssize_t s1_write (struct file *, const char __user *, size_t, loff_t *);
//int s1_close (struct inode *, struct file *);

struct file_operations fops=
{
open:s1_open,
read:s1_read,
write:s1_write,
release:s1_close
};

