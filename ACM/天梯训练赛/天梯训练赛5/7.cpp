#include<bits/stdc++.h>
using namespace std;
int main()
{	char ans;
	int p1,p2,cnt1,cnt2;
	cnt1=cnt2=0;
	cin>>p1>>p2;
	for(int i=0;i<3;i++)
	{
		int x;
		cin>>x;
		if(x==0) cnt1++;
		else cnt2++;
	}
	if(p1>p2&&cnt1>0||cnt1==3) 
	{
		printf("The winner is a: %d + %d",p1,cnt1);
	}
	else printf("The winner is b: %d + %d",p2,cnt2);
}
