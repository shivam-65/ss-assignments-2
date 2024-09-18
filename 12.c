/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("inside child pid= %d\n", getpid());
        printf("parent id= %d\n", getppid()); // as parent terminated we can't get parent id in child process so we will get different value;
        int status=kill(getppid(),SIGKILL);
        if(status==0){
            printf("Parent is killed Chiled is now orphen\n");   
            sleep(10);
        }else{
            perror("Error while killing parent process!");
        }
    }
    else
    {
        // inside parent
        while(1);
    }
    return 0;
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
inside child pid= 16350
parent id= 16349
Parent is killed Chiled is now orphen
Killed
*/
