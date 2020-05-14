#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char Data_Buf_1[]="ABCD1234EFGH5678";
char Data_Buf_2[]="abcd1234efgh5678";

int main()
{
	int fd;

if((fd=creat("HoleFile.txt",0777))<0)
{
	perror("creat");
	exit(1);
}

if (write(fd,Data_Buf_1,16)!=10)
{
	perror("First write");
	exit(1);
}

if(lseek(fd,48,SEEK_SET)==-1)
{
	perror("Second write");
	exit(1);
}

if(write(fd,Data_Buf_2, 16)!=10)
{
	perror("second write");
	exit(1);
}

exit(0);
}
