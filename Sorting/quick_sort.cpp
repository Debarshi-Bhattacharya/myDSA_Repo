#include<bits/stdc++.h>
using namespace std;

int partition(int *arr,int start,int end)
{
    int pivot=arr[end];
    int partitionIndex=start;
    for(int i=start;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(arr[partitionIndex],arr[end]);
    return partitionIndex;
}

void quicksort(int *arr,int start,int end)
{
    if(start<end)
    {
        int p=partition(arr,start,end);
        quicksort(arr,start,p-1);
        quicksort(arr,p+1,end);
    }
}

int main()
{
    int arr[]={70,90,80,10,60,30,40,50};
    quicksort(arr,0,7);
    for(auto x:arr)
        cout<<x<<" ";
    return 0;
}