#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<sys/mman.h>
int main(int argc, char* argv[])
{
    int i;
    pid_t pid;
    const int SIZE=4096;
    void *shmptr;
    int shmid=shmget((key_t)1122,4096,0666|IPC_CREAT);
    shmptr=shmat(shmid,NULL,0666);

    if(argc>1)
    {
        sscanf(argv[1],"%d",&i);
        if(i<1)
        {
            printf("Invalid input\n");
            return 0;
        }
    }
    else
    {
        printf("Parameters not entered\n");
        exit(1);
    }
    pid=fork();
    if(pid==0)
    {
        execlp("./odd","odd",argv[1],NULL);
    }
    else if(pid>0)
    {
        wait(NULL);
        printf("Parent: CHild has terminated\n");
        printf("Parent printing\n");
        printf("%s\n",(char*)shmptr);
        shmdt(shmptr);
    }
    return 0;
}
