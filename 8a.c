/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("SIGSEGV caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;

    status = signal(SIGSEGV, (void *)print);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGSEGV); //// Send segmentation fault signal
    }
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
SIGSEGV caught
*/
