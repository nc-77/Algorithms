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
using namespace std;
ll N,k;
struct mat
{
	ll a[15][15];
};
mat mul(mat A,mat B)
{	mat C;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			C.a[i][j]=0;
			for(int k=0;k<N;k++)
			C.a[i][j]+=(A.a[i][k]*B.a[k][j])%9973;
		}
	return C;
}
mat mpow(mat A,ll n)
{
	mat c;
	memset(c.a,0,sizeof(c.a));
	for(int i=0;i<N;i++)
	c.a[i][i]=1;
	while(n)
	{
		if(n&1) c=mul(c,A);
		A=mul(A,A);
		n>>=1;
	}
	return c;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	mat matt;
		ll ans=0;
		cin>>N>>k;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			cin>>matt.a[i][j];
		matt=mpow(matt,k);
		for(int i=0;i<N;i++)
		{
			ans+=matt.a[i][i];
			ans=ans%9973;	
		}
		
		cout<<ans<<endl;
	}
}
