#include<bits/stdc++.h>
using namespace std;
int n,m,flag;
double rate[35][35];
//struct node
//{
//	string s;
//	int num;
//}money[35];
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				rate[i][j]=max(rate[i][j],rate[i][k]*rate[k][j]);
				
			}
	for(int i=1;i<=n;i++)
	if(rate[i][i]>1.0) flag=1;
}
int main()
{	int cnt=1;
	while(cin>>n&&n!=0)
	{	map<string,int>mp;
		string s;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			mp[s]=i;
		}
		cin>>m;
		//int t1,t2;
		string s1,s2;
		double cost;
		memset(rate,0,sizeof(rate));
		for(int i=1;i<=n;i++)
		rate[i][i]=1;
		while(m--)
		{
			cin>>s1>>cost>>s2;
			rate[mp[s1]][mp[s2]]=cost;
		}
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//			cout<<rate[i][j]<<endl;
		flag=0;
		floyd();
		if(flag) 
		printf("Case %d: Yes\n",cnt++);
		else  printf("Case %d: No\n",cnt++);
		
	}
} 
