#include<bits/stdc++.h>
using namespace std;
int t[1002][1002];
int knapSack(int W, int wt[], int val[], int n) 
{ 
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0||j==0)
            {
                t[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][W];
}
int main()
{
    int W=15;
    int n=5;
    int wt[5]={5,2,10,8,6};
    int val[5]={60,15,30,80,20};
    cout<<knapSack(W,wt,val,n);
}
