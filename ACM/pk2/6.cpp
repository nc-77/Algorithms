#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
struct node
{
    int x,y;//x 奇数 y偶数
}t[maxn];

int main()
{
   int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        a[i]=a[i]%2;
        if(a[i]==1)t[i%k].x++;
        else t[i%k].y++;
    }
    ll ans=0,cnt=0;
    int mx,minn=inf;
   for(int i=0;i<k;i++)
   {
       if(t[i].x>t[i].y) ans+=t[i].y,cnt++;
       else ans+=t[i].x;
        if(abs(t[i].x-t[i].y)<minn) 
        mx=i,minn=abs(t[i].x-t[i].y);
   }
   if(cnt%2==1) 
   {
       ans=ans+abs(t[mx].x-t[mx].y);
   }       
  
  cout<<ans<<endl;
   return 0;
}
