#include<bits/stdc++.h>
using namespace std;
int main()
{	int cnt=0;
	string s;
	getline(cin,s);
	s+=' ';
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='6')
		{
			cnt++;
		}
		if(s[i]!='6')
		{
			if(cnt>9)  cout<<"27";
			else if(cnt>3) cout<<'9';
			else 
			{
				while(cnt--)
				cout<<'6';
				
			}
		if(i!=s.size()-1)	cout<<s[i];
			cnt=0;
		}
		
	}
 } 
