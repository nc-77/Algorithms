#include<bits/stdc++.h>
using namespace std;
int n,c,r,d[1050][1050];
map<string,int>mp;
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{	int js=1;
	while(cin>>n>>c>>r&&!(n==0&&c==0&&r==0))
	{	char s[15],s1[15],s2[15];
		char c1,c2;
		int cost,num[10050];
		int cnt=1,k=0,ans=0;
		memset(d,0x3f,sizeof(d));
		mp.clear(); 
		
		for(int i=1;i<=c+1;i++)
		{
			scanf("%s",s);
			if(mp[s]==0)
			{
				mp[s]=cnt++;
			}
			//puts(s);
			num[k++]=mp[s];	
		}
		while(r--)
		{
			scanf("%s %c-%d-%c %s",s1,&c1,&cost,&c2,s2);
			//printf("%s %c-%d-%c %s",s1,c1,cost,c2,s2);
			if(mp[s1]==0) mp[s1]=cnt++;
			if(mp[s2]==0) mp[s2]=cnt++;
			 if(c1=='<')
			d[mp[s2]][mp[s1]]=min(d[mp[s2]][mp[s1]],cost);
			if(c2=='>')
			d[mp[s1]][mp[s2]]=min(d[mp[s1]][mp[s2]],cost);
		}
		floyd();
		for(int i=1;i<=c;i++)
		{
			ans+=d[1][num[i]]+d[num[i]][1];
		}
		printf("%d. %d\n",js++,ans);
	}
}
