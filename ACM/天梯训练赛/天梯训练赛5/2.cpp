#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	int n,m,cnt=0;
	cin>>n>>m;
	int num=pow(26,n)-m;
	while(n--)
	{
		a[cnt++]=num%26;
		num/=26;
	}
	for(int i=cnt-1;i>=0;i--)
	{
		char ch=a[i]+'a';
		cout<<ch;
	}
 } 
