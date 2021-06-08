#include<bits/stdc++.h>
#define ll long long
using namespace std;
int g,p,l,t;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='G'||s[i]=='g') g++;
		if(s[i]=='P'||s[i]=='p') p++;
		if(s[i]=='L'||s[i]=='l') l++;
		if(s[i]=='T'||s[i]=='t') t++;
	}
	while(g>0||p>0||l>0||t>0)
	{
		if(g>0) 
		{
			cout<<'G';
			g--;
		}
		if(p>0) 
		{
			cout<<'P';
			p--;
		}
		if(l>0) 
		{
			cout<<'L';
			l--;
		}
		if(t>0) 
		{
			cout<<'T';
			t--;
		}
	}
}
