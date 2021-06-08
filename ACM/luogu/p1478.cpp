#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct node
{
    int x,y;
}m[maxn];
bool cmp (node n,node m)
{
    return n.y<m.y;
}
int main()
{
   int n,s;
   cin>>n>>s;
   int a,b;
   cin>>a>>b;
   a+=b;
    for(int i=1;i<=n;i++) cin>>m[i].x>>m[i].y;
    sort(m+1,m+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(m[i].x<=a&&s>=m[i].y) s-=m[i].y,ans++;
    }
    cout<<ans<<endl;
   //system("pause");
   return 0;
}
