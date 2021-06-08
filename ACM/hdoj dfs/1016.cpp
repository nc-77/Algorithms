#include<bits/stdc++.h>
using namespace std;
int ss[60],n,a[25],cnt,vis[25];
void dfs(int step,int num)
{	a[step]=num;
	
	if(step==n-1&&ss[num+a[0]]) 
	{
		
		for(int i=0;i<n;i++)
		{
			if(i!=n-1)	printf("%d ",a[i]);
			else printf("%d",a[i]);
		}
		printf("\n");
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]&&ss[i+num])
		{
		
//			printf("\nstep%d\n",step);
//		for(int j=0;j<step;j++)
//			{
//				printf("%d ",a[j]);
//			}
			vis[i]=1;
			dfs(step+1,i);
			vis[i]=0;
		}
		
	}
return ;
}
int main()
{	ss[2]=1;
	int j,flag=1;
	for(int i=3;i<=60;i++)
	{	flag=1;
		for( j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			//cout<<i<<endl;
			ss[i]=1;
		}
	}
	while(cin>>n)
	{	cnt++;
		vis[1]=1;
		printf("Case %d:\n",cnt);
		dfs(0,1);
		
		printf("\n");
	}
}
