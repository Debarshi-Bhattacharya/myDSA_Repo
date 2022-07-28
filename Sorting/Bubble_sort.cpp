#include<bits/stdc++.h>
using namespace std;

void Bubble_Sort(int A[], int n)
{
    int flag;
    for(int i=0;i<n-1;i++)
    {
        flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int A[]={23,5,12,2,87,6,90};
    Bubble_Sort(A,7);
    for(auto x: A)
        cout<<x<<" ";
}