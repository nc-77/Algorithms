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
       int flag=1;
       cin>>n>>k;
       if(k>n) {
           cout<<"NO"<<endl;
           continue;
       }
       if(n%2==1&&k%2==0) {
           cout<<"NO"<<endl;
           continue;
       }
       if(n%2==0&&k%2==0||n%2&&k%2){
           cout<<"YES"<<endl;
           for(int i=1;i<k;i++)
           cout<<1<<" ";
           cout<<n-(k-1)<<endl;
           continue;
       }
       if(n%2==0&&k%2==1){
           if(n<=2*(k-1)) {
               cout<<"NO"<<endl;
           continue;
           }
           cout<<"YES"<<endl;
           for(int i=1;i<k;i++)
           cout<<2<<" ";
           cout<<n-2*(k-1)<<endl;
           continue;
       }
       
   }
   //system("pause");
   return 0;
}
