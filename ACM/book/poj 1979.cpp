#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e2+10;
int cnt,n,m;
char s[maxn][maxn];
int vis[maxn][maxn];
int sx,sy;
void dfs(int x,int y)
{
	if(s[x][y]=='#') return;
	if(vis[x][y]||x>n||x<=0||y>m||y<=0) return;
	
	vis[x][y]=1;
	cnt++;
	
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>m>>n)
    {	if(m==0&&n==0) break;
		set0(s),set0(vis);
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=m;j++)
    		{	cin>>s[i][j];
    			if(s[i][j]=='@')
				sx=i,sy=j; 
			}
			
		
			cnt=0;
			dfs(sx,sy);
		cout<<cnt<<endl;
	}
}

