#include<bits/stdc++.h>
using namespace std;
bool isnum(char ch)
{
    if(ch>='0' && ch<='9')
        return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    string pos;
    getline(cin,pos);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int N=pos.length();
    int i=0;
    int num_pos=0;
    while(i<N)
    {
        while(isnum(pos[i]))
            i++;
        int dist=stoi(pos.substr(0,i));
        if(pos[i]=='R')
            num_pos+=dist;
        if(pos[i]=='L')
            num_pos-=dist;
    }
    int temp=num_pos;
    for(int i=0;i<n;i++)
    {
        if(temp<arr[i])
        {
            temp-=arr[i];
        }
        else if(temp<arr[i])
        {
            temp-=arr[i];
            cout<<"Possible";
            return 0;
        }
        else
        {
            temp=num_pos;
        }
    }
    cout<<"Not Possible";
    
}