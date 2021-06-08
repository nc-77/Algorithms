#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[105],vis[105];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i];
       set0(vis);
      int now=1,last=1;
       for(int i=1;i<=n;i++)
       {
           if(a[i]==now)
           {
               vis[now]=1;
               for(int j=i-1;j>=last;j--)
               {
                  if(a[j+1]<a[j])swap(a[j],a[j+1]);
               }
               last=i;
               for(int i=1;i<=n;i++)
               {
                   if(!vis[i]) 
                   {
                       now=i;
                       break;
                   }

               }
           }
           else
           {
               vis[a[i]]=1;
           }
           
       }
        for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
           cout<<endl;
       }

   //system("pause");
   return 0;
}
