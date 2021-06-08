#include<bits/stdc++.h>
using namespace std;
#define MAX_N 50010
int num[100000+10];
int out[100000+10];
struct node
{
	int nex;
	int data;
};
map<int,node>j;
int main()
{	memset(num,-1,sizeof(num));
	int st,n,last;
	cin>>st>>n;
	num[1]=st;
	for(int i=0;i<n;i++)
	{
		int id,d,nex;
		cin>>id>>d>>nex;
		j[id].data=d;
		j[id].nex=nex;
	}
	for(int i=1;i<=n;i++)
	{
		int x=num[i];

		num[i+1]=j[x].nex;
		if(j[x].nex==-1)
		last=x;		
	}
	int ss=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0) out[i]=i/2;
		else 
		{
			out[i]=n+1+ss-i;
			ss++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int k=out[i];
		int ad=num[k];
		printf("%05d %d ",ad,j[ad].data);
		if(num[out[i+1]]!=-1)
		printf("%05d\n",num[out[i+1]]);
		else 
		printf("-1\n");
		
	}
}

