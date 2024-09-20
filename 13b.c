/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/

#include <sys/types.h> // Import for kill
#include <signal.h>    // Import for kill
#include <unistd.h>    // Import for sleep, _exit
#include <stdio.h>     // Import for perror & printf
#include <stdlib.h> // Import for atoi

void main(int argc, char *argv[])
{
    int killStatus; // Determines success of kill
    pid_t pid;

    if (argc != 2)
    {
        printf("Pass the PID of the process to whom the SIGSTOP signal is to be sent!\n");
        _exit(0);
    }

    pid = atoi(argv[1]);

    killStatus = kill(pid, SIGSTOP);

    if(!killStatus) 
        printf("Successfully sent SIGSTOP signal to process (%d)\n", pid);
    else 
        perror("Error while sending signal!");
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out 45438
Successfully sent SIGSTOP signal to process (45438)
*/
