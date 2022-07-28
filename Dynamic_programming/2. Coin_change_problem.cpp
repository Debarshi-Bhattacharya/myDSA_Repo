class Solution
{
  public:
    long long t[1002][1002];
    long long int count( int S[], int m, int n )
    {
       for(int i=0;i<m+1;i++)
       {
           for(int j=0;j<n+1;j++)
           {
               if(i==0||j==0)
                {
                    if(i==0)
                        t[i][j]=0;
                    if(j==0)
                        t[i][j]=1;
                }
                else if(S[i-1]<=j)
                {
                    t[i][j]=t[i][j-S[i-1]]+t[i-1][j];
                }
                else
                    t[i][j]=t[i-1][j];
           }
       }
       return t[m][n];
    }
};