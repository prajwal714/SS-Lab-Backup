#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
//using namespace std;

int main()
{
    int pid=fork();
    if(pid==0)
    {
        sleep(10);
       printf("Hello from child %d \n",getpid());
    }
    else
    {
       printf("Hello fron parent %d \n",getpid());
    }
    
 return 1;
}