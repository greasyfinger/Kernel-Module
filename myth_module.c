#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/uidgid.h>
#include <linux/cred.h>
#include <linux/moduleparam.h>
#include <linux/unistd.h>
#include <linux/types.h>
#include <linux/syscalls.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("N Narotam");
MODULE_DESCRIPTION("Read the entries of the process task_struct of a process and prints details.");

static int task_id = -1;
struct task_struct *task;
module_param(task_id, int, S_IRUGO);
MODULE_PARM_DESC(task_id, "The pid of the task from command line");

static int __init krnl_init(void)
{
    printk("----------module loaded-----------\n");
    task = pid_task(find_vpid(task_id), PIDTYPE_PID);
    if (task)
    {
        printk("pid      : %d\n", task->pid);
        printk("user_id  : %u\n", task->cred->uid.val);
        printk("pgid     : %d\n", task->group_leader->pid);
        printk("cmd path : %s\n", task->comm);
    }
    else
    {
        printk("NO VALID FUNCTION\n");
    }
    return 0;
}
static void __exit krnl_exit(void)
{
    printk("----------module unloaded-----------\n");
}
module_init(krnl_init);
module_exit(krnl_exit);