#include<bits/stdc++.h>
#define ll long long
#define N 10
using namespace std;
struct mat
{
	ll a[10][10];
};
int m,a[10];
mat mul(mat A,mat B)
{	mat C;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			C.a[i][j]=0;
			for(int k=0;k<N;k++)
			C.a[i][j]+=(A.a[i][k]*B.a[k][j])%m;
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
int main()
{	
	int k,out[10];
	while(cin>>k>>m)
	{	mat init;
		memset(init.a,0,sizeof(init.a));
		int ans=0;
		for(int i=0;i<10;i++)
		{
			cin>>a[i];
			out[i]=9-i;
			init.a[0][i]=a[i];
		}
		if(k<10) 
		{
			cout<<k%m<<endl;
			continue;
		}
		for(int i=1;i<10;i++)
		{
			init.a[i][i-1]=1;
			
		}
		init=mpow(init,k);
		for(int i=0;i<10;i++)
		{	//cout<<init.a[9][i]<<endl;
			ans+=init.a[9][i]*out[i];
			ans%=m;
		}
		cout<<ans<<endl;
	}
}
