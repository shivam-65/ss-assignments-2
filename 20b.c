/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-20. Write two programs so that both can communicate by FIFO -Use one way communication.
*/

#include <sys/types.h> // Import for `open`
#include <sys/stat.h>  // Import for `open`
#include <fcntl.h>     // Import for `open`
#include <unistd.h>    // Import for `read`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    char *file = "./20-fifo";
    int fd = open(file, O_RDONLY); // File descriptor of the FIFO file

    while (1)
    {
        if (fd == -1)
            perror("Error");
        else
        {
            char buf;
            while (read(fd, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
        }
        close(fd);
    }
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
hi
hello
*/
