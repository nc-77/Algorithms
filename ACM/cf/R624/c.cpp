#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e5+10;
int a[30],ans[30],p[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {	set0(a),set0(ans),set0(p);
    	int n,m;
    	cin>>n>>m;
    	string s;
    	cin>>s;
    	
    	for(int i=1;i<=m;i++)
    	cin>>p[i];
    	sort(p+1,p+m+1);
    	int cnt=1;
    	for(int i=0;i<n;i++)
    	{
    		a[s[i]-'a']++;
    		ans[s[i]-'a']++;
    		while(cnt<=m+1&&i==p[cnt]-1)
    		{
    			for(int j=0;j<26;j++)
    			ans[j]+=a[j];
    			cnt++;
    			//debug(ans['e'-'a']);
			}
			
		}
		cout<<ans[0];
		for(int i=1;i<26;i++)
		{
			cout<<" "<<ans[i];
		}
		cout<<endl;
	}
}

