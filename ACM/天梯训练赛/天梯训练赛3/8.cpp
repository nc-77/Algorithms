#include<bits/stdc++.h>
#define ll long long
#define MAX_N 100
using namespace std;
int ra,ca,rb,cb;
struct mat
{
	ll a[MAX_N][MAX_N];
}; 
mat mul(mat A,mat B)
{	mat C;
	for(int i=0;i<ra;i++)
		for(int j=0;j<cb;j++)
		{
			C.a[i][j]=0;
			for(int k=0;k<ca;k++)
			C.a[i][j]+=(A.a[i][k]*B.a[k][j]);
		}
	return C;
}
int main()
{
	mat a,b;
	cin>>ra>>ca;
	for(int i=0;i<ra;i++)
		for(int j=0;j<ca;j++)
		cin>>a.a[i][j];
	cin>>rb>>cb;
	for(int i=0;i<rb;i++)
		for(int j=0;j<cb;j++)
		cin>>b.a[i][j];
	if(ca!=rb)  
	{
		printf("Error: %d != %d",ca,rb);
		
	}
	else
	{
		mat c=mul(a,b);
		cout<<ra<<" "<<cb<<endl;
		for(int i=0;i<ra;i++)
		{
			for(int j=0;j<cb;j++)
			{
				printf("%d",c.a[i][j]);
				if(j!=cb-1)
				printf(" ");
			}
			printf("\n");
		}
			
	}
}
