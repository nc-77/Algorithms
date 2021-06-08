#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=4e3+10;
int qz[maxn][3],vis[maxn];
int main()
{	string s;
	cin>>s;
	int len=s.size();
	
	int k=0;
	while(k<len&&s[k]==')') k++;
	while(k<len&&s[k]=='(') k++;
	if(k==len) 
	{
		puts("0");
		return 0;
	 } 
	 int last=len;
	for(int i=0;i<last;i++)
	{	
		if(s[i]=='(')
		{
			for(int j=last-1;j>=i+1;j--)
			{
				if(s[j]==')')
				{
					vis[i]=vis[j]=1;
					last=j;
					break;
				}
				
			}
		}
	}
	 puts("1");
	int cnt=0;
	for(int i=0;i<len;i++)
	 if(vis[i]) cnt++;
		
	 cout<<cnt<<endl;
	 int flag=1;
	 for(int i=0;i<len;i++)
	 if(vis[i]) 
	 {
	 	if(flag) cout<<i+1;
	 	else cout<<" "<<i+1;
	 	flag=0;
	 }
}

