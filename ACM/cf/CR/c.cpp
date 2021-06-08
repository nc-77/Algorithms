#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int a[maxn],b[maxn];
int main()
{	ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int c1,c2;
    for(int i=0;i<n;i++)
    {
    	if(a[i]%p!=0)
    	{
    		c1=i;
			break; 
			} 
	}
	 for(int i=0;i<m;i++)
    {
    	if(b[i]%p!=0)
    	{
    		c2=i;
			break; 
			} 
	}
	cout<<c1+c2<<endl;
}

