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
    int n;cin>>n;
    if(n%2==1) 
    {
    	puts("-1");
    	return 0;
	}
    string s;
    cin>>s;
    int s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='(') s1++;
    	else s2++;
	}
	if(s1!=s2) 
	{
    	puts("-1");
    	return 0;
	}
	s1=s2=0;int ans=0;
	for(int i=0;i<n;)
	{	int flag=0,cnt=0;
		do 
		{
		if(s[i]=='(') s1++;
    	else s2++;
    	if(s1<s2) flag=1;
    	i++;
    	cnt++;
		}while(s1!=s2&&i<n);
		if(flag) ans+=cnt;
	}
	cout<<ans<<endl;
}

