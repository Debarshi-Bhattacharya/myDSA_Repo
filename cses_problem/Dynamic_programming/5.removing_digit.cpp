#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int flag=0;
	while(n!=0){
	    int m=0;
	    for(char c:to_string(n))
	    {
	        m=max(m,c-'0');
	    }
	    n-=m;
	    flag++;
	}
	cout<<flag;
}
