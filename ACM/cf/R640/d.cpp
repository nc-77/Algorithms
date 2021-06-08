#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int s[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>s[i];
       if(n==1) {
           cout<<1<<" "<<s[1]<<" "<<0<<endl;
           continue;
       }
       int i=1,j=n,cnt=0,a=0,b=0,sa=0,sb=0;
       while(i<=j)
       {
           for(int k=i;k<=j;k++){
               sa+=s[k];
               if(sa>sb||k==j){
                   i=k+1;
                   a+=sa;
                   sb=0;
                   cnt++;
                   break;
               }
           }
           
           for(int k=j;k>=i;k--){
               sb+=s[k];
               if(sb>sa||k==i) {
                   j=k-1;
                   b+=sb;
                   sa=0;
                   cnt++;
                   break;
               }
           }
          
           //debug(i),debug(j),debug(a),debug(b);
       }
       cout<<cnt<<" "<<a<<" "<<b<<endl;
   }
   //system("pause");
   return 0;
}
