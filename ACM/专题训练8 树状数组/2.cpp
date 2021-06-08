#include<bits/stdc++.h>
using namespace std;
int d[100000+10];
int a[100000+10];
int main()
{	int n;
	while(cin>>n&&n)
	{
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		int t=n;
		while(t--)
		{
			int x,y;
			cin>>x>>y;
			d[x]++;
			d[y+1]--;
			
		}
		for(int i=1;i<=n;i++)
			{
				a[i]=a[i-1]+d[i];
				if(i!=n) printf("%d ",a[i]);
				else printf("%d\n",a[i]);
			}
	}
 } 
