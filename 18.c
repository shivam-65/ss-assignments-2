/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipe1[2]; // Pipe for ls -l and grep
    int pipe2[2]; // Pipe for grep and wc
    pid_t pid1, pid2;

    // Create the first pipe
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

    // Create the second pipe
    if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    // Fork the first child to execute ls -l
    if ((pid1 = fork()) == -1) {
        perror("fork1");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) { // First child
        // Close unused ends of the pipes
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[0]); // Close read end of pipe2
        close(pipe2[1]); // Close write end of pipe2

        // Redirect stdout to pipe1
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[1]); // Close the original write end of pipe1

        // Execute ls -l
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls"); // If exec fails
        exit(EXIT_FAILURE);
    }

    // Fork the second child to execute grep
    if ((pid2 = fork()) == -1) {
        perror("fork2");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) { // Second child
        // Close unused ends of the pipes
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        // Redirect stdin to read from pipe1
        dup2(pipe1[0], STDIN_FILENO);
        close(pipe1[0]); // Close the original read end of pipe1

        // Redirect stdout to pipe2
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe2[1]); // Close the original write end of pipe2

        // Execute grep
        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep"); // If exec fails
        exit(EXIT_FAILURE);
    }

    // Parent process
    close(pipe1[0]); // Close read end of pipe1
    close(pipe1[1]); // Close write end of pipe1
    close(pipe2[1]); // Close write end of pipe2

    // Wait for both children to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // Now count the number of lines using wc
    int count = 0;
    char buffer[128];

    // Read from pipe2 and count the lines
    while (read(pipe2[0], buffer, sizeof(buffer)) > 0) {
        count += (int)(strlen(buffer) / 2); // Each line ends with a newline
    }
    close(pipe2[0]); // Close the read end of pipe2

    printf("Total number of directories: %d\n", count);

    return 0;
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
Total number of directories: 0
*/
