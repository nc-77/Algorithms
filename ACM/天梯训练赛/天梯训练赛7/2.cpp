#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int h,m,sum;
	scanf("%d:%d",&h,&m);
	
	if(h>=0&&h<=12) 
	{
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
		return 0;
	}
	if(m==0)
	sum=h-12;
	else sum=h-12+1;
	while(sum--)
	cout<<"Dang";
}
