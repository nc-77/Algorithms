#include<bits/stdc++.h>
#define ll long long
#define MAX_N 100
using namespace std;
struct mat
{
	ll a[MAX_N][MAX_N];
}; 
mat mul(mat A,mat B,int mod)
{	mat C;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			C.a[i][j]=0;
			for(int k=0;k<N;k++)
			C.a[i][j]+=(A.a[i][k]*B.a[k][j])%mod;
		}
	return C;
}
mat mpow(mat A,int n)
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
ll quickpow(ll x,ll n,ll mod)
{
	ll res=1;
	while(n)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
