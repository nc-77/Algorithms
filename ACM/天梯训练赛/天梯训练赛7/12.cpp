#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	double mon;
	int sum;
	int id;
}s[10000+10];
bool cmp(node s1,node s2)
{
	if(s1.mon>s2.mon) return true;
	else if(s1.mon==s2.mon)
	{
		if(s1.sum>s2.sum) return true;
		else if(s1.sum==s2.sum) 
		return s1.id<s2.id;
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{	s[i].id=i;
		int k;
		cin>>k;
		int sum=0;
		while(k--)
		{
			int x;
			int y;
			cin>>x>>y;
			s[x].mon+=y;
			sum+=y;
			s[x].sum++;
		}
		s[i].mon-=sum;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<s[i].id<<" ";
		printf("%.2f",s[i].mon/100);
		if(i!=n) printf("\n");
	}
}
