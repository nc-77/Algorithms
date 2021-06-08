#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       int x=0,y=0,sum=0,m;
        for(int i=1;i<=n;i++) {
           
            cin>>m;
            if(m%2) x++;
            else y++;
            sum+=m;
        }
      if(k==n){
          if(sum%2) cout<<"yes"<<endl;
          else cout<<"no"<<endl;
      }
      else {
          if(x&&y) cout<<"yes"<<endl;
          else if(x==0&&y) cout<<"no"<<endl;
          else {
              if(k%2) cout<<"yes"<<endl;
              else cout<<"no"<<endl;
          }
      }
        
        

   }
   //system("pause");
   return 0;
}
