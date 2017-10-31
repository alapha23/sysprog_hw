System Programming Homework6
===

> Name: Gao Zhiyuan
> ID:   2017-81842

q6
---

This program is actually a part of a shell, which reads command from the input and execute the specified command. 

There are several challenges:
* Path to command might be among /bin/, /sbin/, /user/bin, /user/sbin/, which means we need to search for the command. 
* The length and number of arguments might vary. For example, it might be:
	* cat "a very long string which is out of your buffer but i will just stop herer\n"
	* gcc -Wall -fPIC -O1 -std=c89 ./q7.c -o so_okay_we_have_many_flags

Note that in the second example we also need to specify which one is argument and which is flag, e.g. so_okay_we_have_many_flag is argument specified for the flag -o while ./q7.c is also an argument. 

Considering the above challengs, to completely finish the homework needs significant effort that I will not do it completely unless there are bonus points for me. 

I enabled single flag command usage in /bin/ directory. Commands like ls -al, ps -Al can be used. Also, commands could be used with no flags, such as ls. 

It will not search the current directory, nor other directoreis for built-in commands. Thus, ./q6 or ./htop will not be working. 


q7
---

We are supposed to catch the write signal sent to the read-only memory block. 

My first thought was to catch the write signal and then return. But I found that PROT_WRITE is not the write signal, it is the signal for making the block write-allowed. That is why I am stuck, I do not know which signal I should catch. 

In the handler, I do not know what is uarg. And I also think arguments passed to the handler is fixed. So the uarg pointer is also confusing me. 

The above confusing points are the reason my q7.c is half done. 


