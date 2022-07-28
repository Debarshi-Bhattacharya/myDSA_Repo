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
void  Merge_Sort_recursive(int A[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        Merge_Sort_recursive(A,l,mid);
        Merge_Sort_recursive(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}
int main()
{
    int A[]={23,5,12,2,87,6,90};
    Merge_Sort_recursive(A,0,7);
    for(auto x: A)
        cout<<x<<" ";
}