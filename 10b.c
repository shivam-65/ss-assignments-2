/*
Name:- Padaliya Shivam
Roll No:- MT2024107
program:- 10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print(){
    printf("Caught SIGSEGV\n");
}
void main()
{
    int status;
    struct sigaction act;
    
    act.sa_handler=print;//function that replace default action of signal SIGSEGV
    act.sa_flags=0;
    status = sigaction(SIGSEGV,&act,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGSEGV);
    }
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
Caught SIGSEGV
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("Caught SIGINT\n");
}
void main()
{
    int status;
    struct sigaction act;

    act.sa_handler = print; // function that replace default action of signal SIGSEGV
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act, NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGINT);
    }
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
Caught SIGINT
*/
