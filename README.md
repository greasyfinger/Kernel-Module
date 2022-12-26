
# Kernel Module
A kernel module that takes in pid of running process as command line argument and prints pid, user id, group id and command path
of the process, from its task_struct.

## Deployment

myth_module.c has the code for the kernel module, and the make file generates 
the myth_module.ko file which can be loaded or unloaded to kernel space.

after running make run the following commands to run the code

```bash
ps
```
this should list currently running processes along with with their pid,
choose pid of any of the processes and run
(lets say the task of running processes is 804)
```bash
insmod myth_module.ko task_id=804
```
the details of the processes should now be visible on the kernel message buffer, which can be viewed via the following command

```bash
dmesg
```
if the "NO VALID FUNCTION", means a valid pid wasn't enetered.

To unload the kernel module simply run

```bash
rmmod myth_module.ko
```

## Acknowledgements

 - [How to build a kernel module](https://blog.sourcerer.io/writing-a-simple-linux-kernel-module-d9dc3762c234)
 - [get task_struct from pid](https://stackoverflow.com/questions/8547332/efficient-way-to-find-task-struct-by-pid)

