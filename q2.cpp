#include<bits/stdc++.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the values of array: "<<endl;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }



    __pid_t id1=fork();
    __pid_t id2=fork();
    if(id1>0&&id2>0)
    {
        cout<<"Enter the number to find frequency of: "<<endl;
        int num;
        cin>>num;
        int frq=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]==num)
            frq++;
        }
        cout<<"The frequency of : "<<num<<"  is : "<<frq<<endl;
       
    }
    else if(id1==0&&id2>0)
    {
        sort(arr.begin(),arr.end());
        cout<<"The sorted array is: "<<endl;
        for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    }
    else if(id1>0&&id2==0)
    {
        int evenNum=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]%2==0)
            evenNum++;
        }
        cout<<"Total even nums: "<<evenNum<<endl;
    }
    else
    {
         int evenSum=0;
        for(i=0;i<n;i++)
        {
            if(arr[i]%2==0)
           evenSum+=arr[i];
        }
        cout<<"Total sum of even nums: "<<evenSum<<endl;
    }
    

    return 0;
}