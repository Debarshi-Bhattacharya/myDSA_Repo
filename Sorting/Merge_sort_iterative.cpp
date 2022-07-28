#include<bits/stdc++.h>
using namespace std;
void Merge(int A[],int l,int mid,int h)
{
    int i=l, j=mid+1, k=l;
    int B[100];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else 
            B[k++]=A[j++];  
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void Merge_Sort(int A[],int n)
{
    int p,i,l,mid,h;
    for(p=2;p<=n;p*=2)
    {
        for(i=0;i+p-1<n;i++)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            Merge(A,l,mid,h);
        }
    }
    if(p/2<n)
        Merge(A,0,p/2-1,n-1);
}
int main()
{
    int A[]={23,5,12,2,87,6,90};
    Merge_Sort(A,7);
    for(auto x: A)
        cout<<x<<" ";
}