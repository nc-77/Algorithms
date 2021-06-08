#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
int main()
{
   
   int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int mi=inf,mx=-1;
        set0(a);
        getchar();
        for(int i=1;i<=n;i++)
        {
            int x;
            
            scanf("%d",&x);
            x+=500000;
            mi=min(mi,x);
            mx=max(mx,x);
            a[x]=1;
        }
        int cnt=1;
        for(int i=mx;i>=mi;i--)
        {
            //debug(i);
            if(a[i]==0) continue;
            
            if(cnt<m)
            {
                printf("%d ",i-500000);
                cnt++;
            }
            else if(cnt==m) {
                printf("%d\n",i-500000);
                cnt++;
            }
            else break;
        }
    }
   //system("pause");
   return 0;
}
