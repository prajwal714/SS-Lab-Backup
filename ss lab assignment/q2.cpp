#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
pid_t pid;
char command[20];

if((pid=fork())<0)
{
	perror("Fork");
	exit(0);
}
else if(pid==0)
{
	printf("Enter a command without any arguments \n");
	scanf("%s",command);
system("command");
}

else
{
	if(wait(&status)<0)
	{
	perror("Wait");
	}
}
return 0;
}
