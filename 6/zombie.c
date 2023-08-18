#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    pid_t my_pid,parent_pid,child_pid;
    child_pid=fork();
    if(child_pid<0)
    {
        printf("\n Fork failed,exititng\n");
        exit(1);
    }
    if(child_pid==0)
    {
        printf("[child] this is child process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[child]My pid is %d\n",my_pid);
        printf("[child] my parent pid is %d\n",parent_pid);
        exit(1);
        }
    else{
        printf("[parent] this is parent process\n");
        my_pid=getpid();
        parent_pid=getppid();
        printf("[parent]My pid is %d\n",my_pid);
        printf("[parent] my parent pid is %d\n",parent_pid);
        //printf("[parent] Parent exiting\n");
        printf("parent process sleeping\n");
        sleep(10);
        printf("the child process with pid %d has ended but still has an access to the process table\n",child_pid);
        printf("[parent]it is therefore a zombie process\n");
    }
    return 0;
        
}
