#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<char,int>mp;
int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s2.size();i++)
	mp[s2[i]]=1;
	for(int i=0;i<s1.size();i++)
	{
		if(!mp[s1[i]])  cout<<s1[i];
	}
}
