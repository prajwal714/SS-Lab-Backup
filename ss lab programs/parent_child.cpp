/*
Fork system call having no arguments
returns process id of the child to the parent process and zero to child process
after creation of process both parent and child process start executing from the next instruction

Question - To write a c program to simulate the operation of ls command. 
*/

#include<bits/stdc++.h>
#include<unistd.h>


using namespace std;

int main()
{
    int pid;
    pid = fork();
    if(pid==0)
    {
        
        cout<<"Child Process "<<getpid()<<" Parent id: "<<getppid()<<endl;
        // sleep(20);
    } 
    else
    {
        sleep(15);
        cout<<"Parent Process "<<getpid()<<" Child id: "<<pid<<endl;
    } 
}
