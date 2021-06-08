#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct node
{
    int x,id;
}a[maxn];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i].x,a[i].id=i;
       sort(a+1,a+n+1,cmp);
       int mx=0,mi=inf;
        for(int i=1;i<=n;i++)
        {
            //add(i,a[i].id,n);
            mx=max(mx,a[i].id);
            mi=min(mi,a[i].id);
            //debug(mx),debug(mi);
            if(mx-mi+1==i)
            cout<<1;
            else cout<<0;
        }
        cout<<endl;
   }
   //system("pause");
   return 0;
}
