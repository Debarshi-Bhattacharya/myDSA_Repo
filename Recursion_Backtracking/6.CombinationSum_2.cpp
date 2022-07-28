/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.*/

class Solution {
public:
    void findComb(int ind, int target,vector<int>&ds,vector<vector<int>> &res,vector<int>&arr)
    {
        if(target==0)
        {
            res.push_back(ds);
            return;
        }
                
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            findComb(i+1,target-arr[i],ds,res,arr);
            ds.pop_back();
        }  
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        vector<vector<int>>res;
        findComb(0,target,ds,res,candidates);
        return res;
    }
};