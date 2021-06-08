#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<'='<<x<<endl
const int maxn=1e6+10;
int bit[maxn+1],a[100000+10],minn[100000+10],maxx[100000+10],vis[100000+10];
int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=1000000+10)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
int main()
{   memset(minn,0x3f,sizeof(minn));
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int x;
            cin>>x;
            x++;
            minn[i]=min(minn[i],x);
            maxx[i]=max(maxx[i],x);
            if(x>minn[i]) vis[i]=1;
        }
        if(vis[i]) cnt++;
        if(!vis[i])
        add(maxx[i],1);
    }
    //debug(cnt);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {   if(!vis[i])
        {   ans+=cnt;
            ans+=n-cnt-sum(minn[i]);
        }
        else ans+=n;
    }
    cout<<ans<<endl;
}
