/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:- 2. Write a program to print the system resource limits. Use getrlimit system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

void print_rlimit(const char *resource_name, int resource) {
    struct rlimit rl;
    
    if (getrlimit(resource, &rl) == -1) {
        perror("getrlimit");
        exit(EXIT_FAILURE);
    }
    
    printf("%s:\n", resource_name);
    printf("  Soft limit: %ld\n", (long)rl.rlim_cur);
    printf("  Hard limit: %ld\n", (long)rl.rlim_max);
    printf("\n");
}

int main() {
    // Print limits for different resources
    print_rlimit("File size", RLIMIT_FSIZE);
    print_rlimit("Data size", RLIMIT_DATA);
    print_rlimit("Stack size", RLIMIT_STACK);
    print_rlimit("Core file size", RLIMIT_CORE);
    print_rlimit("CPU time", RLIMIT_CPU);
    print_rlimit("Maximum number of open files", RLIMIT_NOFILE);
    print_rlimit("Maximum number of processes", RLIMIT_NPROC);
    print_rlimit("Maximum number of file locks", RLIMIT_LOCKS);
    print_rlimit("Maximum number of addresses", RLIMIT_AS);
    print_rlimit("Maximum number of memory pages", RLIMIT_MEMLOCK);

    return 0;
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
File size:
  Soft limit: -1
  Hard limit: -1

Data size:
  Soft limit: -1
  Hard limit: -1

Stack size:
  Soft limit: 8388608
  Hard limit: -1

Core file size:
  Soft limit: 0
  Hard limit: -1

CPU time:
  Soft limit: -1
  Hard limit: -1

Maximum number of open files:
  Soft limit: 1024
  Hard limit: 1048576

Maximum number of processes:
  Soft limit: 30324
  Hard limit: 30324

Maximum number of file locks:
  Soft limit: -1
  Hard limit: -1

Maximum number of addresses:
  Soft limit: -1
  Hard limit: -1

Maximum number of memory pages:
  Soft limit: 1003278336
  Hard limit: 1003278336
*/
