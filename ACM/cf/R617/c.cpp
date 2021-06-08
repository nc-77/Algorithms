#include <bits/stdc++.h>
#define ll  long long
using namespace std;
 
int main(){
int t;
cin>>t;
int n;
string s;
	while(t--){
		cin>>n>>s;
		int x=0,y=0;
		map<pair<int,int>,int>m;
	int	l=0,r=n+1;
	m[{0,0}]=1;
	for(int i=0;i<n;i++){
			if(s[i]=='L') x--;
			if(s[i]=='R') x++;
			if(s[i]=='U') y++;
			if(s[i]=='D') y--;
			if(m[{x,y}]) if(i-m[{x,y}]<r-l) l=m[{x,y}],r=i;
			m[{x,y}]=i+2;
		}
		if(l==0) cout<<-1<<"\n";
		else cout<<l<<" "<<r+1<<"\n";
	}
}
