#include<bits/stdc++.h>
using namespace std;

void Insertion_Sort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int key=A[i];
        while(j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int main()
{
    int A[]={23,5,12,2,87,6,90};
    Insertion_Sort(A,7);
    for(auto x: A)
        cout<<x<<" ";
}