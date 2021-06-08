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
#define MAX_N 2
using namespace std;
ll m=10000;
struct mat
{
	ll a[MAX_N][MAX_N];
};
mat mul(mat A,mat B)
{	mat C;
	for(int i=0;i<MAX_N;i++)
		for(int j=0;j<MAX_N;j++)
		{
			C.a[i][j]=0;
			for(int k=0;k<MAX_N;k++)
			C.a[i][j]+=(A.a[i][k]*B.a[k][j])%m;
		}
	//cout<<"here"<<C.a[1][0]<<" "<<endl;
	return C;
}
mat mpow(mat A,ll n)
{
	mat c;
	memset(c.a,0,sizeof(c.a));
	for(int i=0;i<MAX_N;i++)
	c.a[i][i]=1;
	while(n)
	{
		if(n&1) c=mul(c,A);
		//cout<<c.a[1][0]<<endl;
		A=mul(A,A);
		n>>=1;
	}
	return c;
}
int main()
{	ll n;
	while(cin>>n&&n!=-1)
	{
		mat ans;
		ans.a[0][0]=1,ans.a[0][1]=1,ans.a[1][0]=1,ans.a[1][1]=0;
		ans=mpow(ans,n);
		cout<<ans.a[1][0]%10000<<endl;
	}
} 
