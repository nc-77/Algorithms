#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
ll a[maxn];
map<ll,int>mp;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {	mp.clear();
    	ll n,x;
    	cin>>n>>x;
    	for(int i=0;i<n;i++)
    	{
    		cin>>a[i];
    		mp[a[i]]=1;
		}
    	sort(a,a+n);
    	if(mp[x]) puts("1");
    	else
    	{
    		int ans=ceil(x*1.0/a[n-1]);
    		cout<<max(ans,2)<<endl;
		}
		
	}
}

