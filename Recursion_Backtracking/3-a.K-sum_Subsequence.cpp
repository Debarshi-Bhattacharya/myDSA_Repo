
/*check if there is a subsequence having sum K*/
#include<bits/stdc++.h>
using namespace std;

bool printSeq(int ind,vector<int>&seq,int arr[],int n,int &sum,int k)
{
    if(ind==n)
    {
        if(sum==k)
        {
            return true;
        }
        else return false;
    }
    //pick condition
    seq.push_back(arr[ind]);
    sum+=arr[ind];
    if(printSeq(ind+1,seq,arr,n,sum,k))// if this return true that means we found a subseq having sum k
    //no need to go for further recursion calls
        return true;

    //not pick condition
    seq.pop_back();
    sum-=arr[ind];
    if(printSeq(ind+1,seq,arr,n,sum,k))// if this return true that means we found a subseq having sum k
    ////no need to go for further recursion calls
        return true;
        
    return false; // no such subseq presents
}

int main()
{
    int arr[3]={3,1,2};
    vector<int>seq;
    int sum=0;
    int k=1;
    if(printSeq(0,seq,arr,3,sum,k))
    {
        for(auto &it:seq)
            cout<<it<<" ";
    }
    else
        cout<<"no such sub sequence is present";
}