#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<string>> h;
	vector<string> v;
	string ip,op;
	
	for(int i=0;i<10;i++){
	    vector<string> t;
	    for(int j=0;j<10;j++){
	    cin>>ip;
	    t.push_back(ip);
	    }
	    h.push_back(t);
	}
	
	
	 for(int i=0;i<10;i++){
	     if(i%2!=0){
	      for(int j=9;j>=0;j--){
	          v.push_back(h[i][j]);
	      }
	     }
	     else{
	         for(int j=0;j<10;j++){
	          v.push_back(h[i][j]);
	      }
	     }
	  }
	v.push_back("");
	reverse(v.begin(),v.end());
	
    getline(cin,op);
    getline(cin,op);
    getline(cin,op);
   
    int curr=0;
    
    string p;
    
    int y=0;
    int sn=0,ld=0;
    
    for(int i=0;i<op.size();i+=2){
           int m=op[i]-'0';
           curr+=m;
           p=v[curr];
           
           if(p[0]=='S'){
               int k=0;
               int l=p.size()-1;
               for(int j=2;j<l;j++){
                   k=k*10+p[j]-'0';
               }
               curr=k;
               sn++;
           }
           else if(p[0]=='L'){
               int k=0;
               int l=p.size()-1;
               for(int j=2;j<l;j++){
                   k=k*10+p[j]-'0';
               }
               curr=k;
               ld++;
           }
           else if(curr==100){
               y=1;
               break;
           }
    }
    
    if(y==0){
        cout<<"Not possible"<<" "<<sn<<" "<<ld<<" "<<curr;
    }
    else{
        cout<<"Possible"<<" "<<sn<<" "<<ld<<" ";
    }
	return 0;
}