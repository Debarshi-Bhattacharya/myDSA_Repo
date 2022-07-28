
#include<bits/stdc++.h>
using namespace std;

void printSeq(int ind,vector<int>&seq,int arr[],int n)
{
    if(ind==n)
    {
        for(auto &i: seq)
        {
            cout<<i<<" ";
            
        }
        if(seq.size()==0)
        {
            cout<<"{}";
        }
        cout<<endl;
        return;
    }
    //pick condition
    seq.push_back(arr[ind]);
    printSeq(ind+1,seq,arr,n);

    //not pick condition
    seq.pop_back();
    printSeq(ind+1,seq,arr,n);
}

int main()
{
    int arr[3]={3,1,2};
    vector<int>seq;
    printSeq(0,seq,arr,3);
}