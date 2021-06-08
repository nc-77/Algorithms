#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int x,y;
}pos[2000];
bool cmp(node p1,node p2)
{
	if(p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y)) return true;
	return false;
	
}
char step[10500];
int main()
{	
	int t;
	cin>>t;
	while(t--)
	{
		memset(pos,0,sizeof(pos));
		int n,nx=0,ny=0,cnt=0,cnts=0;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>pos[i].x>>pos[i].y;
		sort(pos,pos+n,cmp);
		for(int i=0;i<n;i++)
		{
			while(pos[i].x>nx) 
			{
				nx++;
				step[cnts++]='R';
				if(nx==pos[i].x&&ny==pos[i].y) cnt++;
			}
			while(pos[i].y>ny) 
			{
				ny++;
				step[cnts++]='U';
				if(nx==pos[i].x&&ny==pos[i].y) cnt++;
			}
		}
		if(cnt==n) 
		{
			puts("YES");
			for(int i=0;i<cnts;i++)
			putchar(step[i]);
			printf("\n");
		}
		else puts("NO");
	}
}
