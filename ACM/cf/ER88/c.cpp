#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int h,c;
double fun(int x)
{
    int m=x/2;
    int n=x-x/2;
    double res=(n*h+m*c)*1.0/x;
    return res;
}
signed main()
{
   //ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while(T--)
   {
       int t;
       cin>>h>>c>>t;
        if(h+c==2*t) {
            cout<<2<<endl;
            continue;
        }
        int ans=max(1ll,(h-c)/(2*t-(h+c)));
        //debug(ans);
        double mi=abs(fun(ans)-t);
        int flag=ans;
        for(int i=max(1ll,ans-10);i<=ans+10;i++)
        {
            double x=abs(fun(i)-t);
            if(x<mi){
                mi=x;
                flag=i;
            }
        }
        cout<<flag<<endl;
   }
   //system("pause");
   return 0;
}
