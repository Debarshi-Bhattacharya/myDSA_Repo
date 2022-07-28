/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates 
where the chosen numbers sum to target.You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times.
Two combinations are unique if the frequency of at least one of the chosen numbers is different.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findComb(int ind, int target,vector<int>&ds,vector<vector<int>> &res,vector<int>&arr)
    {
        if(ind==arr.size())
        {
            if(target==0)
                res.push_back(ds);
            return;
        }
        
        if(arr[ind]<=target)
        {
            ds.push_back(arr[ind]);
            findComb(ind,target-arr[ind],ds,res,arr);
            ds.pop_back();
        }
        findComb(ind+1,target,ds,res,arr);   
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>res;
        findComb(0,target,ds,res,candidates);
        return res;
    }
};