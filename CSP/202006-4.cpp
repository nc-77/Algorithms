#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define mod 998244353
#define ll long long
const int N=4;
using namespace std;
struct mat
{
	ll a[10][10];
}; 
mat mul(mat A,mat B)
{	mat C;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			C.a[i][j]=0;
			for(int k=0;k<N;k++)
			C.a[i][j]=(C.a[i][j]+(A.a[i][k]*B.a[k][j])%mod)%mod;
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
	
   // for(int i=0;i<N;i++)
   // {
   //    for(int j=0;j<N;j++)
   //    {
   //       cout<<c.a[i][j]<<" ";
   //    }
   //    cout<<endl;
   // }
   return c;
}
int main()
{
   ll n;
   string s;
   cin>>n>>s;
   mat x;
   memset(x.a,0,sizeof(x.a));
   x.a[0][2]=x.a[1][0]=x.a[2][1]=x.a[2][3]=x.a[3][2]=x.a[3][3]=1;
   mat ans;
    ans=mpow(x,n);
   if(s=="1") cout<<ans.a[0][0]<<endl;
   else if(s=="2") cout<<ans.a[1][0]<<endl;
   else if(s=="4") cout<<ans.a[2][0]<<endl;
   else if(s=="6") cout<<ans.a[3][0]<<endl;
   else cout<<0<<endl;
   return 0;
}
