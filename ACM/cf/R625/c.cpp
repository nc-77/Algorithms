#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int vis[200],pre[200],nex[200];
char s[200];
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    int flag=1;
    for(int i=2;i<=n;i++) pre[i]=i-1;
    for(int i=1;i<=n-1;i++) nex[i]=i+1;
    int ans=0;
    while(flag)
    {	flag=0;
    	char mx=0;
		int mi=0;
    	for(int i=1;i<=n;i++)
    	{	 
    		if(vis[i]) continue;
    		if(i==1&&s[i]-s[nex[i]]==1||i==n&&s[i]-s[pre[i]]==1)
    		{	flag=1;
    			if(s[i]>mx)
    			{
    				mx=s[i];
    				mi=i;
				}
			}
			else if(i!=1&&i!=n&&(s[i]-s[pre[i]]==1||s[i]-s[nex[i]]==1))
			{	flag=1;
				if(s[i]>mx)
    			{
    				mx=s[i];
    				mi=i;
				}
			}
		}
		if(!flag) break;
		//debug(mi);
		vis[mi]=1;
		nex[pre[mi]]=nex[mi];
		pre[nex[mi]]=pre[mi];
		ans++;
	}
    
	cout<<ans<<endl;
}

