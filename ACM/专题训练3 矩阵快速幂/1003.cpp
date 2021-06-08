#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define int long long
using namespace std;
int N,k;
#define  M 1000000007
struct mat
{
	int a[35][35];
};
mat mul(mat A,mat B)
{	mat C;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			C.a[i][j]=0;
			for(int k=0;k<N;k++)
			{
				C.a[i][j]+=(A.a[i][k]*B.a[k][j])%M;
				C.a[i][j]%=M;
			}
		}
	return C;
}
mat mpow(mat A,int n)
{
	mat c;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(i==j) c.a[i][j]=1;
			else c.a[i][j]=0;
		}
	while(n)
	{
		if(n&1) c=mul(c,A);
		A=mul(A,A);
		n>>=1;
	}
	return c;
}
mat madd(mat A,mat B)
{
	mat c;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
	c.a[i][j]=(A.a[i][j]+B.a[i][j])%M;
	return c;
}
mat sum(mat x,int k)
{
    mat tmp,y;
    if(k==1) return x;
    tmp=sum(x,k/2);
    if(k&1){
        y=mpow(x,k/2+1);
        tmp=madd(mul(y,tmp),tmp);
        return madd(tmp,y);
    }
    else{
        y=mpow(x,k/2);
        return madd(mul(y,tmp),tmp);
    }
};
signed main()
{	ios::sync_with_stdio(false);
	cin>>N>>k;
	mat a,sum1;
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		cin>>a.a[i][j];
		a.a[i][j]%=M;
	}
	sum1=sum(a,k);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
		{
			if(j!=N-1) cout<<sum1.a[i][j]%M<<" ";
			else cout<<sum1.a[i][j]%M;	
		}
	if(i!=N-1)	cout<<endl; 
	}
	
	return 0;
}
