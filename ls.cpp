#include<bits/stdc++.h>
#include<dirent.h>
using namespace std;

int main()
{
    char dirname[10];
    DIR *p;
    struct dirent *d;
    // printf("Enter directory name\n");
    // scanf("%s",dirname);
    char *s = getenv("PWD");
    // cout<<s<<endl;
    p=opendir(s);
    if(p==NULL)
    {
        perror("Cannot find directory");
        exit(-1);
    }
    while(d=readdir(p))
    {
        DIR *x;
        x = opendir(d->d_name);
        if(x==NULL) printf("%s\n",d->d_name);
        else if(d->d_name!=".") printf("%s is a DIR\n",d->d_name);
    }
}

