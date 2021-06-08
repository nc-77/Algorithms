#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main()
{
	string s,word;
	while(getline(cin,s)&&s!="#")
	{	mp.clear();
		word.clear();
		int ans=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			{
				word+=s[i];
				//cout<<word<<" "<<ans<<endl;
			}
			if(!word.empty()&&(i==s.size()-1||s[i]==' '))
			{
				if(!mp[word])
				{	
					mp[word]=1;
					ans++;
					//cout<<word<<" "<<ans<<endl;
					
					//cout<<word<<" "<<ans<<endl;
				}
				word.clear();
			}
		}
		cout<<ans<<endl;
	}
 } 
