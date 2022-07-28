/* print the number of subsequences of the given array those have K-sum*/
#include<bits/stdc++.h>
using namespace std;

bool printSeq(int ind,vector<int>&seq,int arr[],int n,int &sum,int k)
{
    if(ind==n)
    {
        if(sum==k)
        {
            return 1;//if sum is equal to target sum k then we got one subsequence
        }
        else return 0;
    }
    //pick condition
    seq.push_back(arr[ind]);
    sum+=arr[ind];
    int l= printSeq(ind+1,seq,arr,n,sum,k);//returns the number of possible subsequneces forming k-sum from left of the 
    //recursion tree


    //not pick condition
    seq.pop_back();
    sum-=arr[ind];
    int r=printSeq(ind+1,seq,arr,n,sum,k);//returns the number of possible subsequneces forming k-sum from right of the 
    //recursion tree

    return l+r;
        
}

int main()
{
    int arr[3]={3,1,2};
    vector<int>seq;
    int sum=0;
    int k=4;
    cout<<printSeq(0,seq,arr,3,sum,k);
}