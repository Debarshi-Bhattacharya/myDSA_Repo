#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int m;
    m=n;
    if(n==1 || n==3)
        cout<<"Yes"<<endl;
    else{
    for(int i=2;i<n;i++)
    {
        if(m%i==0)
        {
            cout<<"No"<<endl;
            break;
        }
        else if(m<i)
        {
            cout<<"Yes"<<endl;
            break;
        }
        else
            m=m-m/i;
    }
    }
}
