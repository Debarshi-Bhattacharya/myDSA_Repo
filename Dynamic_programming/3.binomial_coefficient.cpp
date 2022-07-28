
A binomial coefficient C(n, k) can be defined as the coefficient of x^k in the expansion of (1 + x)^n.

The value of C(n, k) can be recursively calculated using the following standard formula for Binomial Coefficients.  
 C(n, k) = C(n-1, k-1) + C(n-1, k)
 C(n, 0) = C(n, n) = 1

class Solution{
public:
    int mod=1e9+7;
    int t[1002][802];##constrain 1<=n<=1000,1<=r<=800
    int nCr(int n, int r){
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<=min(i,r);j++)
            {
                if(j==0||j==i)
                    t[i][j]= 1;
                else
                    t[i][j]=(t[i-1][j-1]+t[i-1][j])%mod;
            }
        }
        return t[n][r];
    }
};