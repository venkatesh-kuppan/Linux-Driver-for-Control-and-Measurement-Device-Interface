# Linux-Driver-for-Control-and-Measurement-Device-Interface
This project aims at writing a basic skeleton driver of Control and Measurement Interface Device Interface



I have used the following comedi-0.7.70 and comedilib-0.7.22. The basic installation for these libraries remain the same.

The file skeleton.c can be used as refernce for the implementation of driver.
The file test_program is the user space test program to test the newly added kernel module.



Steps:
1. The skeleton.c should be placed in the path comedi/drivers.
2. Make file edit: In module_PROGRAMS add CMDI.ko 
3. Goto root of comedi distribution and run command "autoreconf" and a new makefile.in will be generated.
4. Run commands "make" and "make install".
5. use command modprobe to load the .ko i.e the kernel object.
6. Finally run the command "comedi_config /dev/comedi CMDI"


Tips: Use dmesg extensively and appropriately to monitor the kernel logs when you load the module. 

