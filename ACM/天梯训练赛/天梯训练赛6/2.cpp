#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
	int id;
	int num;
}vis[1010];
bool cmp(node a,node b)
{	if(a.num>b.num) return true;
	else if(a.num==b.num) return a.id>b.id;
	else return false;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x;
			cin>>x;
			vis[x].num++;
			vis[x].id=x;
		}
	}
	sort(vis,vis+1010,cmp);
	cout<<vis[0].id<<" "<<vis[0].num<<endl;
	
}
