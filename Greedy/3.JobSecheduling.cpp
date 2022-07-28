// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(Job j1,Job j2)
    {
        if(j1.profit>j2.profit) return true;
        return false;
        
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int>result;
        sort(arr,arr+n,comparator);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) 
            maxi = max(maxi, arr[i].dead);
        vector<int>schedule(maxi+1,-1);
        int maxProf=arr[0].profit;
        int jobDone=1;
        schedule[arr[0].dead]=arr[0].id;
        for(int i=1;i<n;i++)
        {
            int j=arr[i].dead;
            while(j>=1)
            {
                if(schedule[j]==-1)
                {
                    schedule[j]=arr[i].id;
                    maxProf+=arr[i].profit;
                    jobDone++;
                    break;
                }
                j--;
            }
        }
        result.push_back(jobDone);
        result.push_back(maxProf);
        return result;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends