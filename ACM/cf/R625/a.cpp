#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int a[maxn],b[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    cin>>b[i];
    int x=0,y=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
    	if(a[i]==1&&b[i]==0) x++;
    	if(a[i]==0&&b[i]) y++;
    	if(a[i]==b[i]) cnt++;
	}
	if(cnt==n||x==0) puts("-1");
	else
	{
		cout<<y/x+1<<endl;
	}
}

