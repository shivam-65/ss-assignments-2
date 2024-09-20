/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-19. Create a FIFO file by
a. mknod command
b. mkfifo command
*/

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main() {
    int stat = mkfifo("myFifo", 0777);
    if(stat == -1) {
        perror("FIFO creation using mkfifo failed");
        exit(1);
    } else {
        printf("FIFO Success using mkfifo!!!\n");
    }

    // Create a FIFO using mknod with permissions
    stat = mknod("mknodFifo", S_IFIFO | 0666, 0);
    if(stat == -1) {
        perror("FIFO creation using mknod failed");
        exit(1);
    } else {
        printf("mknod FIFO Success!!!\n");
    }

    return 0;
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
FIFO Success using mkfifo!!!
mknod FIFO Success!!!
*/
