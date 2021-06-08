#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=5e4+10;
int n;
int  num[maxn],bit[12][12][maxn];
void change(int s,int a,int k,int c)
{
	while(a<=n)
	{
		bit[s][k][a]+=c;
		a+=a&-a;
	}
}
ll ask(int s,int k,int x)
{	ll ans=0;
	while(x>0)
	{
		ans+=bit[s][k][x];
		x-=x&-x;
	}
	return ans;
}
int main()
{	ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    while(cin>>n)
    {	set0(bit);
    	for(int i=1;i<=n;i++)  cin>>num[i];
	    int q;
	    cin>>q;
	    while(q--)
	    {
	    	int op,a,b,k,c;
	    	cin>>op;
	    	if(op==2)
	    	{
	    		cin>>a;
	    		ll ans=0;
	    		for(int i=1;i<=10;i++)
	    			for(int j=1;j<=i;j++)
	    			if((a-j)%i==0)
	    			ans+=ask(j,i,a);
	    		cout<<num[a]+ans<<endl;
			}
	    	if(op==1)
	    	{
	    		cin>>a>>b>>k>>c;
				change((a+k-1)%k+1,a,k,c);
				change((a+k-1)%k+1,a+(b-a)/k*k+1,k,-c);
			}
		}
	}
    
}

