/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-21. Write two programs so that both can communicate by FIFO -Use two way communications.
*/

#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    char *s; 
    int fd;  
    long int size = 100;
    char *file = "./21a-fifo";
    while (1)
    {
        fd = open(file, O_RDONLY); 

        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
            close(fd);
        }

        fd = open(file, O_WRONLY);
        if (fd == -1){
            perror("Error");
        }
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }


    }
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
hey

enter message:
hey bro
how r u

enter message:
fine

^C
*/
