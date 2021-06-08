#include<bits/stdc++.h>
using namespace std;
const int MAXN=200;
int n,m;
char f[MAXN][MAXN];
void dfs(int x,int y)
{
	f[x][y]='.';
	for(int i=-1;i<=1;++i)
	{
		for(int j=-1;j<=1;++j)
		{	int nx=x+i,ny=y+j;
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&f[nx][ny]=='W')
			dfs(nx,ny);
		}
	}
}
int main()
{
	int ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		cin>>f[i][j];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(f[i][j]=='W')
			{
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
return 0;	
} 
