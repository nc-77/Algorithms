#include<bits/stdc++.h>
using namespace std;
long long  a[2010],b[2010];
map<long long,int>ma,mb;
const int inf=0x3f3f3f3f;
int main()
{
	long long len,m,temp,ans=inf,k;
	cin>>len>>m;
	for(int i=0;i<len;i++)
	{
		cin>>a[i];
		ma[a[i]]++;
	}
	for(int i=0;i<len;i++)
	{
		cin>>b[i];
		mb[b[i]]++;
	}
	if(ma==mb) 
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<len;i++)
	{	ma.clear();
		if(a[i]<=b[0])temp=b[0]-a[i];
		else temp=b[0]+m-a[i];
		cout<<temp<<endl;
		for(int j=0;j<len;j++)
		{	k=(a[j]+temp)%m;
			//printf("k%d ",k);
			ma[k]++;
			
			//printf("ma[%d]%d ",k,ma[k]);
			
		}
		//printf("mb[1]%d,mb[2]%d\n",mb[1],mb[2]);
		if(ma==mb) 
		{
			cout<<"here"<<endl;
			ans=min(ans,temp);
		}
	}
	cout<<ans<<endl;
 } 
