#include<bits/stdc++.h>
using namespace std;
char s[1010][1010];
int vis[1010],num,flag;
void dfs(int x)
{	int end=strlen(s[x])-1;
	if(s[x][end]=='m')
	{
		flag=1;
		return;
	}
	
	for(int i=0;i<num;i++)
	{	if(s[i][0]==s[x][end]&&!vis[i])
		{
			vis[i]=1;
			dfs(i);
			vis[i]=0;
		}
	}
return;
}
int main()
{	int i=0;
	while(cin>>s[i++])
	{
		if(strcmp(s[i-1],"0"))
		continue;
		else
		{	num=i-1;
			flag=0;
			//cout<<num<<endl;
			for(int j=0;j<i;j++)
			{
				if(s[j][0]=='b')
				{
					memset(vis,0,sizeof(vis));
					vis[j]=1;
					dfs(j);
				}
			}
			if(flag) cout<<"Yes."<<endl;
			else cout<<"No."<<endl;
			i=0;
			memset(s,0,sizeof(s));
		}
		
	}
 } 
