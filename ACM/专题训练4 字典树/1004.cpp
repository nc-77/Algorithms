#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
string s,cs;
int main()
{	ios::sync_with_stdio(false);
	while(cin>>s)
	{	string s2;
		if(s=="START") continue;
		if(s=="END") break;
		cin>>s2;
		mp[s2]=s;
	}
	getline(cin,s);
	while(getline(cin,s))
	{
		if(s=="START") continue;
		if(s=="END") break;
		int len=s.size();
		for(int i=0;i<len;i++)
		{
			if(s[i]<='z'&&s[i]>='a'||s[i]<='Z'&&s[i]>='A')
			cs+=s[i];
			else
			{
				if(mp[cs]!="")cout<<mp[cs];
				else cout<<cs;
				cout<<s[i];
				cs.clear();
			}
		}
		cout<<"\n";
		
	}
} 
