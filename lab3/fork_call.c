#include<unistd.h>
#include<stdlib.h>

void main()
{
    int pid=fork();
  

    if(pid==0)
    {
          //  printf("Hello %d \n",getpid());

    }
    else
    {
        
        printf("Hello from child %d \n",getpid());
    }
    
      int pid2=fork();

      if(pid==0)
      {
                     // printf("Hello %d \n",getpid());

      }
      else
      {
                printf("Hello from child %d \n",getpid());

      }
     printf("Hello from child %d \n",getpid());

      
}