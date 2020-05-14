#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
   pid_t child=fork();
   if(child>0)
   {
       printf("This is parent %d, my child is %d \n",getpid(),child);
   }
   else if(child==0)
   {
       printf("This is child %d, my parent is %d \n",getpid(),getppid());
   }
   else
   {
       
       printf("child process error");
   }
   
    //fork();
    return 0;
}