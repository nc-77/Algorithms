#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
signed main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       int l=0,r=1e10+10;
       while(r-l>1)
       {
           int mid=l+r>>1;
           
            if(mid-mid/n==k) {
                if(mid%n==0) mid--;
                cout<<mid<<endl;
                break;
            }
            else if(mid-mid/n<k) l=mid;
            else r=mid;
       }
   }
   //system("pause");
   return 0;
}
