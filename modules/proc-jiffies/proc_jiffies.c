#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>

#define BUFFER_SIZE 128
#define PROC_NAME "jiffies"

static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos);

static const struct proc_ops hello_proc_ops = {
    .proc_read = proc_read,
};

// This function is called when the module is loaded
static int __init proc_init(void)
{
    if (proc_create(PROC_NAME, 0444, NULL, &hello_proc_ops) == NULL)
    {
        pr_err("Failed to create /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }

    pr_info("/proc/%s created\n", PROC_NAME);
    return 0;
}

// This function is called when the module is removed
static void __exit proc_exit(void)
{
    remove_proc_entry(PROC_NAME, NULL);
    pr_info("/proc/%s removed\n", PROC_NAME);
}

// This function is called each time /proc/jiffies is read
static ssize_t proc_read(struct file *file, char __user *usr_buf,
                         size_t count, loff_t *pos)
{
    char buffer[BUFFER_SIZE];
    int len;

    if (*pos > 0)
        return 0;

    len = scnprintf(buffer, sizeof(buffer), "%lu\n", (unsigned long)jiffies);

    if (len > count)
        len = count;

    if (copy_to_user(usr_buf, buffer, len))
        return -EFAULT;

    *pos += len;
    return len;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module exposing jiffies through /proc");
MODULE_AUTHOR("Youssef");
MODULE_VERSION("1.0");