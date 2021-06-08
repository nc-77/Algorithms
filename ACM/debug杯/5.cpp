#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
struct node
{
    int a,b;
}p[maxn];

signed main()
{ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,v;
       cin>>n>>v;
       set0(p);
        for(int i=1;i<=n;i++) cin>>p[i].a;
        for(int i=1;i<=n;i++) cin>>p[i].b;
        
        int ans=p[1].a,nv=v;
        for(int i=1;i<n;i++)
        {
            if(p[i].b<nv) 
            {
                nv-=p[i].b;
                ans+=abs(p[i+1].a-p[i].a);
            }
            else if(p[i].b==nv)
            {
            	nv=v;
            	ans+=p[i+1].a+p[i].a;
			}
            else 
            {   p[i].b-=nv;
            	ans+=p[i].a;
                int k=p[i].b/v;
                int m=p[i].b%v;
                ans+=p[i].a*k*2;
               if(m) ans+=p[i].a+abs(p[i+1].a-p[i].a);
               else ans+=p[i+1].a;
                nv=v-m;
            }

        }
        if(p[n].b<=nv) ans+=p[n].a;
        else
        {
        	p[n].b-=nv;
        	ans+=p[n].a;
        	int k=p[n].b/v;
        	int m=p[n].b%v;
        	if(m) k++;
        	ans+=p[n].a*k*2;
		}
       
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
