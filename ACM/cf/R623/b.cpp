#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int maxn=1e5+10;
ll q[maxn];
int main()
{	int t;
	cin>>t;
	
	while(t--)
	{	memset(q,0,sizeof(q));
		ll a,b,m,ans=0;
		cin>>a>>b>>m;
		string s;
		cin>>s;
		int f1=1,f2=1;
		int len=s.size();
		if(s[0]=='A') ans+=a;
		else ans+=b;
 		for(int i=1;i<len;i++)
		{
			while(i<len-1&&s[i]==s[i-1]) 
			i++;
			q[i]=ans;
			//cout<<i<<" "<<ans<<endl;
			if(s[i]=='A') ans+=a;
			else ans+=b;
			
			
			
		}
		if(q[len-1]<=m) puts("1");
		else
		{
			for(int i=1;i<len;i++)
			{
				if(q[i]==0) continue;
				if(q[len-1]-q[i]<=m) 
				{
					cout<<i+1<<endl;
					break;
				}
			}
		}
		
	}
   
}

