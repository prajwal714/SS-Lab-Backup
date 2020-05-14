#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
    int pid=fork();

    if(pid==0)
    {
       // printf("Hello from child %d \n",getpid());

        execlp("ping","ping","127.0.0.1","-c","10",NULL);

    }
    else
    {     
        printf("Hello from parent %d \n",getpid());
    }
    
}