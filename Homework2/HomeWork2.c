/* Bedemariam Degef
   Homework 2  
   10/30/2020
   File description:C code to create three processes;
                    a grandparent (G), a parent (P) and a child (C) */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Driver code
int main()
{
    int pid, status1, status2;
    pid = fork();
    switch (pid)
    {
    case -1: // when an error occurs during the fork process.
        printf("Fork error.");
        break;
    case 0:
        pid = fork();
        switch (pid)
        {
        case -1:
            /* If an error occurred */
            printf("Fork error");
            break;
        case 0:

            /* This code is executed by the child process */
            printf("I am the child process C and my pid is %d. ", getpid());
            printf("My parent P has pid %d. ", getppid());
            printf("My grandparent G has pid %d. \n", getppid() - 1);
            break;

        default:

            /* This code is executed by the parent process */
            wait(&status1);
            printf("I am the parent process P and my pid is %d.", getpid());
            printf(" My parent G has pid %d. \n", getppid());
            break;
        }
        break; 
        
    default:

        /* This code is executed by the by the grandparent process */
        wait(&status2);
        printf("I am the Grandparent process G and my pid is %d.", getpid());

        break;
    }
}