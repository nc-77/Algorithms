#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,c6=0,c1=0;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='6') c6++;
		if(s[i]=='1') c1++;
	}
	cout<<min(c1,c6-1)<<endl;
}
