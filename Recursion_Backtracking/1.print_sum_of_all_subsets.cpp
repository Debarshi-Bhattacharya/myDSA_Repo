
#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    void dofunc(int ind,int sum, vector<int>&res,vector<int> arr, int N) 
    {
        if(ind==N)
        {
            res.push_back(sum);
            return;
        }
        
        dofunc(ind+1,sum+arr[ind],res,arr,N);
        dofunc(ind+1,sum,res,arr,N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>res;
        dofunc(0,0,res,arr,N);
        sort(res.begin(),res.end());
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
} 