#include<bits/stdc++.h>
using namespace std;
int solveOdd(string s,int girl,int boy)
{
  int N=s.size();
  int num=(N+1)/2;
  int one=0,zero=0;
  for(int i=0;i<N;i++)
  {
    if(i%2==0)
    {
      if(s[i]=='G')
        one++;
      else
        zero++;
    }
  }
  if(girl>boy)
    return num-one;
  else
    return num-zero;
}
int solveEven(string s)
{
  int N=s.size();
  int one_odd=0,one_even=0;
  for(int i=0;i<N;i++)
  {
    if(s[i]=='G')
    {
      if(i%2)
        one_odd++;
      else
        one_even++;
    }
  }
  return min(N/2-one_odd,N/2-one_even);
}

int solve(string s)
{
  int N=s.size();
  int girl=0,boy=0;
  for(int i=0;i<N;i++)
  {
    if(s[i]=='G')
		girl++;
    else
      	boy++;
  }
  if(N%2)
  {
  	int res=solveOdd(s,girl,boy);
    return res;
  }
  else
  {
    int res=solveEven(s);
    return res;
  }
}

int main()
{
  string str;
  cin>>str;
  cout<<solve(str);
}