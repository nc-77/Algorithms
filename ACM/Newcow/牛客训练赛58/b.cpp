#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int main()
{
    //freopen("in.txt","r",stdin);
    string s;
    cin>>s;
    int ans=0;
    int f1=0,f0=0;
    for(int i=0;i<s.size();i++)
    {
    	if(s[i]=='1')
    	{
    		f1=1;
		}
		else f0=1;
		if(f1&&f0) 
		{
			ans++;
			f1=f0=0;
		}
	}
	cout<<ans<<endl;
}

