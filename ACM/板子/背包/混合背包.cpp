#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int f[maxn];
struct node
{
	int v,w;
};
vector<node>goods;
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	int v,w,s;
    	cin>>v>>w>>s;
    	if(s==-1) goods.push_back({v,w});
    	else if(s==0) s=m/v;
    	if(s>0) 
    	{
    		int k=1;
	   		while(s>=k)
	   		{	goods.push_back({k*v,k*w});
	   			s-=k;
	   			k=k*2;
			}
			if(s>0) goods.push_back({s*v,s*w});
		}
	}
	for(auto good:goods)
   		for(int j=m;j>=good.v;j--)
   		f[j]=max(f[j],f[j-good.v]+good.w);
   
   cout<<f[m]<<endl;
}

