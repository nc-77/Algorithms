#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int main()
{
    //ios::sync_with_stdio(false);
    string s,ns,js;
    cin>>s;
    int n=s.size(),flag=1;
    if(n==1) 
	{
		puts("-1");
		return 0;
	}
    for(int i=1;i<=n;i++)
    {	if(n%i!=0) continue;
		ns=s.substr(0,i);
    	flag=1;
    	for(int j=i;j<=n-i;j+=i)
    	{
    		if(ns!=s.substr(j,i))
    		{
    			flag=0;
    			break;
			}
		}
		if(flag) break;
	}
	if(ns!=s) cout<<ns<<endl;
	else puts("-1");
}

