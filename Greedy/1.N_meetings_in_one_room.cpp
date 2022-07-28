
#include <bits/stdc++.h>
using namespace std;

class meeting
{
    
    public:
        int s;
        int e;
        int pos;
    meeting(int s,int e,int pos)
    {
        this->s=s;
        this->e=e;
        this->pos=pos;
    }
};
bool comparator(meeting m1,meeting m2)
{
    if(m1.e<m2.e) return true;
    if(m1.e>m2.e) return false;
    if(m1.pos<m2.pos) return true;
    return false;
}
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        
        vector<meeting>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(meeting(start[i],end[i],i+1));
        }
        sort(arr.begin(),arr.end(),comparator);
        int limit=arr[0].e;
        int count=1;
        for(int i=1;i<n;i++){
            if(arr[i].s>limit)
            {
                count++;
                limit=arr[i].e;
            }
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} 