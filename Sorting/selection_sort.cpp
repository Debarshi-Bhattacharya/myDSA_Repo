#include<bits/stdc++.h>
using namespace std;


void selectionSort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i,k=i;
        for(;j<n;j++)
        {
            if(A[j]<A[k])
                k=j;
        }
        swap(A[i],A[k]);
    }
}

int main()
{
    int A[]={8,6,3,2,5,4};
    selectionSort(A,sizeof(A)/sizeof(A[0]));
    for(auto x:A)
        cout<<x;
}