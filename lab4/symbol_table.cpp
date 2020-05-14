
//gcc producer-consumer.c -o producer-consumer.out
#include<bits/stdc++.h>
using namespace std;

struct symbol{
    string label,desc;
};

void insert(vector<symbol> &v)
{
    cout<<"Enter label and description: "<<endl;
    string label,desc;
    cin>>label>>desc;

    symbol temp;
    temp.label=label;
    temp.desc=desc;

    v.push_back(temp);
    return;
}

int search(vector<symbol> &v,string label)
{
   
    int flag=0;
    int i;
    for(i=0;i<v.size();i++)
    {
        if(v[i].label==label)
        {
            cout<<"Symbol found"<<endl;
            cout<<"Desc: "<<v[i].desc<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"symbol not found"<<endl;
        return -1;
       
    }
    return i;
}

void modify(vector<symbol> &v)
{
    string label,desc;
    cout<<"Enter the label to modify: "<<endl;
    cin>>label;
    int index=search(v,label);
    if(index!=-1)
    {
        cout<<"Enter the new Desc: ";
        string desc;
        cin>>desc;
        v[index].desc=desc;
    }
    else
    {
        cout<<"the symbol dosent exist"<<endl;
    }

    return;

}

void display(vector<symbol> &v)
{
    if(v.size()==0)
    {
        cout<<"table is empty"<<endl;
        return;
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].label<<"--->"<<v[i].desc<<endl;
    }

}

int main()
{
    vector<symbol> v;
    int ex=1;
    while(ex)
    {
        cout<<"Enter 1 for insert, 2 for search, 3 for modify, 4 for display, 5 for exit"<<endl;
        cin>>ex;
        switch(ex)
        {
            case 1: insert(v);
            break;

            case 2:{
                cout<<"Enter symbolt to search"<<endl;
                string symbol;
                cin>>symbol;

                int temp=search(v,symbol);
            }
            break;

            case 3: modify(v);
            break;

            case 4: display(v);
            break;

            case 5: ex=0;
            break;

            default: cout<<"Wrong input "<<endl;
        }
    }


}