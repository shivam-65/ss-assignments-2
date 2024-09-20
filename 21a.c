/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-21. Write two programs so that both can communicate by FIFO -Use two way communications.
*/


#include <sys/types.h> // Import for `mkfifo` & `open`
#include <sys/stat.h>  // Import for `mkfifo` & `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `write`
#include <stdio.h>     // Import for `perror`

void main()
{
    char *s; // Data to be sent through the buffer
    int fd;  // File descriptor of the FIFO file
    long int size = 100;
    char *file = "./21a-fifo";
    mkfifo(file, S_IRWXU);
    while (1)
    {
        fd = open(file, O_WRONLY);
        if (fd == -1)
            perror("Error");
        else
        {
            printf("enter message:\n");
            int l = getline(&s, &size, stdin);
            write(fd, s, l);
            close(fd);
        }

        fd = open(file, O_RDONLY); // File descriptor of the FIFO file

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
    }
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
enter message:
hey
hey bro

enter message:
how r u
fine

enter message:
^C
*/
