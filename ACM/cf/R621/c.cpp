#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
map<string,ll>mp;
int main()
{
    //freopen("in.txt","r",stdin);
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0;i<s.size();i++)
    {	string t;
    	t+=s[i];
    	
    	for(int j=0;j<26;j++)
    	{	string p;
    		p+=(char)('a'+j);
			t+=(char)('a'+j);
    		mp[t]+=mp[p];
    		ans=max(ans,mp[t]);
		}
		t.clear();
		t+=s[i];
		mp[t]++;
		ans=max(ans,mp[t]);
	}
	
	cout<<ans<<endl;
	
}

