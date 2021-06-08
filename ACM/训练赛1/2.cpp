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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int f1=0,f2=0;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='R') f1=1;
    	if(s[i]=='L') f2=1;
	}
	if(f1&&!f2||f2&&!f1) cout<<n<<endl;
	else 
	{
		if(s[0]=='L')
		{	int cnt=0;
			for(int i=0;i<n;i++)
			{
				if(s[i]=='L') cnt++;
				else break;
			}
			for(int i=n-1;i>=0;i--)
			{
				if(s[i]=='R') cnt++;
				else break;
			}
			cout<<cnt+1<<endl;
		}
		else
		{	int cnt=0;
			for(int i=n-1;i>=0;i--)
			{
				if(s[i]=='R') cnt++;
				else break;
			}
			cout<<cnt+1<<endl;
		}
	}
}

