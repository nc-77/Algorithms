#include<bits/stdc++.h>
#define ll long long
#define N 4
using namespace std;
struct mat
{
	int a[4][4];
};
int m;
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
	int len,out[4]={9,6,4,2};
	while(cin>>len>>m)
	{	int ans=0;
		if(len==0) 
		{
			cout<<ans<<endl;
			continue;
		}
		mat init;
		memset(init.a,0,sizeof(init.a));
		init.a[0][0]=init.a[0][2]=init.a[0][3]=1;
		init.a[1][0]=init.a[2][1]=init.a[3][2]=1;			
		init=mpow(init,len-1);
		for(int i=0;i<4;i++)
		{	//cout<<init.a[3][i]<<endl;
			ans+=init.a[3][i]*out[i];
			ans%=m;
		}
		cout<<ans<<endl;
	}
 } 
