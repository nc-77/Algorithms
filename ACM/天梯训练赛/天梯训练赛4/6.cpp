#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		int len=s.size();
		int a=s[0]-'0'+s[1]-'0'+s[2]-'0';
		int b=s[len-1]-'0'+s[len-2]-'0'+s[len-3]-'0';
		if(a==b) cout<<"You are lucky!"<<endl;
		else cout<<"Wish you good luck."<<endl;
	}
}
