#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,d[250][250];
void floyd()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{	//cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
			if(d[i][j]>7)
			{
				cout<<"No"<<endl;
				return;
			}
		}
	cout<<"Yes"<<endl;
}
int main()
{
	while(cin>>n>>m)
	{
		memset(d,0x3f,sizeof(d));
		int r1,r2;
		for(int i=0;i<n;i++)
		d[i][i]=0;
		while(m--)
		{
			cin>>r1>>r2;
			d[r1][r2]=d[r2][r1]=1;
		}
		floyd();
	}
} 
