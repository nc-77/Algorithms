#include<bits/stdc++.h>
using namespace std;
int n,m,t,si,sj,ei,ej,flag;
char mp[10][10];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void dfs(int x,int y,int step)
{
	if(step==t&&x==ei&&y==ej) flag=1;
	if(flag) return;
	if(x>n-1||x<0||y>m-1||y<0) return;
	
	for(int i=0;i<4;i++)
	{	if(mp[x+dx[i]][y+dy[i]]!='X')
		{	
			mp[x+dx[i]][y+dy[i]]='X';
//			for(int k=0;k<n;k++)
//			{
//					for(int q=0;q<m;q++)
//				{
//					printf("%c ",mp[k][q]);
//				}
//				printf("\n");
//				}
			dfs(x+dx[i],y+dy[i],step+1);
			mp[x+dx[i]][y+dy[i]]='.';
		}
		
	}
	return ;
}
int main()
{
	while(cin>>n>>m>>t&&!(n==0&&m==0&&t==0))
	{	int numx=flag=0;
		for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					cin>>mp[i][j];
					if(mp[i][j]=='S')
					{
						si=i;
						sj=j;
						mp[i][j]='X';
					}
					else if(mp[i][j]=='D')
					{
						ei=i;
						ej=j;
					}
					else if(mp[i][j]=='X')
					numx++;
				}
			}
			int dis=t-fabs(si-ei)+fabs(sj-ej);
		if(t>m*n-numx-1||dis<0||dis%2==1) 
		{
			cout<<"NO"<<endl;
			continue;
		}
		dfs(si,sj,0);
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
 } 
