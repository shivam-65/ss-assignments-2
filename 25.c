/*
Name:- Padaliya Shivam
Roll No:- MT2024107
Program:-25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
*/

#include <sys/msg.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <time.h>
typedef struct mesg_buffer
{
    /* data */
    long mesg_type;
    char mesg_text[100];
} mesg_buffer;
int main(int argc, char const *argv[])
{
    /* code */
    mesg_buffer message;
    // generate unique no
    key_t key = ftok(".", 1); // projext path is current directory and project id=1
    // create massage queue using msgget
    //  msgget creates a message queue
    //  and returns identifier
    int msgid = msgget(key, 0666 | IPC_CREAT);
    struct msqid_ds buf;
    msgctl(msgid, IPC_STAT, &buf); // IPC_STAT   
    /* Copy  information  from  the  kernel  data  structure associated with msqid into the
    msqid_ds structure pointed to by buf.The caller must have read permission on the message queue. */

        struct ipc_perm msg_perm = buf.msg_perm; /* Ownership and permissions */
    time_t msg_stime = buf.msg_stime;          /* Time of last msgsnd(2) */
    time_t msg_rtime = buf.msg_rtime;          /* Time of last msgrcv(2) */
    time_t msg_ctime = buf.msg_ctime;          /* Time of creation or last modification by msgctl() */
    unsigned long msg_cbytes = buf.msg_cbytes; /* # of bytes in queue */
    msgqnum_t msg_qnum = buf.msg_qnum;         /* # number of messages in queue */
    msglen_t msg_qbytes = buf.msg_qbytes;      /* Maximum # of bytes in queue */
    pid_t msg_lspid = buf.msg_lspid;           /* PID of last msgsnd(2) */
    pid_t msg_lrpid = buf.msg_lrpid;           /* PID of last msgrcv(2) */
    printf("access permission %d\n", msg_perm.mode);
    printf("uid : %d gid : %d \n", msg_perm.uid, msg_perm.gid);
    printf("Time of last msgrcv(2) %ld\n", msg_rtime);
    printf("Time of last msgsnd(2) %ld\n", msg_stime);
    printf("Time of last msgrcv(2) %ld\n", msg_rtime);
    printf("Time of creation or last modification by msgctl() %ld\n", msg_ctime);
    printf("number of bytes in queue %ld\n", msg_cbytes);
    printf("number of messages in queue %ld\n", msg_qnum);
    printf("Maximum number of bytes in queue %ld\n", msg_qbytes);
    printf("PID of last msgsnd(2) %d\n", msg_lspid);
    printf("PID of last msgrcv(2) %d\n", msg_lrpid);
    return 0;
}

/*
shivam@shivam-Vostro-3590:~/Desktop/Handsonlist2/ss-assignments-2$ ./a.out
access permission 438
uid : 1000 gid : 1000 
Time of last msgrcv(2) 0
Time of last msgsnd(2) 0
Time of last msgrcv(2) 0
Time of creation or last modification by msgctl() 1726736130
number of bytes in queue 0
number of messages in queue 0
Maximum number of bytes in queue 16384
PID of last msgsnd(2) 0
PID of last msgrcv(2) 0
*/
