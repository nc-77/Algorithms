#include<bits/stdc++.h>
using namespace std;
int a[3][100000+10];
int main()
{
	int n,q,flag=0;
	cin>>n>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(x==1)
		{
			if(a[x][y]==0)
			{
				a[x][y]=1;
				if(a[x+1][y-1]) flag++;
				if(a[x+1][y]) flag++;
				if(a[x+1][y+1]) flag++;
			}
			else if(a[x][y]==1)
			{
				a[x][y]=0;
				if(a[x+1][y-1]) flag--;
				if(a[x+1][y]) flag--;
				if(a[x+1][y+1]) flag--;
			}
		}
		else 
		{
			if(a[x][y]==0)
			{
				a[x][y]=1;
				if(a[x-1][y-1]) flag++;
				if(a[x-1][y]) flag++;
				if(a[x-1][y+1]) flag++;
			}
			else if(a[x][y]==1)
			{
				a[x][y]=0;
				if(a[x-1][y-1]) flag--;
				if(a[x-1][y]) flag--;
				if(a[x-1][y+1]) flag--;
			}
		}
		if(flag==0) puts("Yes");
		else  puts("No");
	}
 } 
