#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
  int pid;
  while(1)
  {
      pid=fork();
      printf("%d",getpid());
  }
    return 0;
}