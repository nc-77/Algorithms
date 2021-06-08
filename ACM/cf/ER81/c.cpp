#include<bits/stdc++.h>
using namespace std;
int pos[30][100000+10];
int num[30];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{	int flag=1,find=0,ans=1;
		memset(pos,0,sizeof(pos));
		memset(num,0,sizeof(num));
		string s,t;
		cin>>s>>t;
		for(int i=0;i<s.size();i++)
		{
			pos[s[i]-'a'][++num[s[i]-'a']]=i+1;
		}
		for(int i=0;i<t.size();i++)
		{
			if(!pos[t[i]-'a'][1]) 
			{
				flag=0;
				break;
			}
			find=upper_bound(pos[t[i]-'a']+1,pos[t[i]-'a']+num[t[i]-'a']+1,find)-pos[t[i]-'a'];
			if(find>=1&&find<=num[t[i]-'a'])
			find=pos[t[i]-'a'][find];
			else
			{
				ans++;
				find=pos[t[i]-'a'][1];
			}
			
		}
		if(flag) cout<<ans<<endl;
		else puts("-1");
	}
}
