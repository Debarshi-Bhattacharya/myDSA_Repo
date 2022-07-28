#include<bits/stdc++.h>
using namespace std;

int countSeq(int ind,int arr[],int n,int sum,int k)
{
    if(sum>k) return 0;
    if(ind==n)
    {
        if(sum==k)
        {
            return 1;
        }
        else return 0;
    }
    //pick condition
    sum+=arr[ind];
    int l=countSeq(ind+1,arr,n,sum,k);// count given by left recursion tree,i.e,by picking element

    //not pick condition
    sum-=arr[ind];
    int r=countSeq(ind+1,arr,n,sum,k);// count given by right recursion tree,i.e,by not picking element
        
        
    return l+r; // no such subseq presents
}

int main()
{
    int arr[4]={3,1,2,2};
    vector<int>seq;
    int sum=0;
    int k=4;
    cout<<countSeq(0,arr,4,sum,k);
    
}