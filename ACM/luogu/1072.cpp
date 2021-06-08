#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<ll,ll>prime[4];
void fac(ll n,map<ll,ll>&prime)
{
    prime.clear();
    for(int i=2;i<=n/i;i++)
    { 
          while(n%i==0)
        {
            prime[i]++;
            n=n/i;
        }
    }
    if(n>1) prime[n]++;
}
map<ll,ll>xx;
map<ll,ll>cnt;
int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       xx.clear();
       cnt.clear();
       int a0,a1,b0,b1,flag=1;
       cin>>a0>>a1>>b0>>b1;
       fac(b0,prime[2]);
       fac(b1,prime[3]);
       for(auto x:prime[3]){
           int id=x.first;
           int num=x.second;
           if(num<prime[2][id]){
               flag=0;
               break;
           }
           else if(num>prime[2][id]){
               xx[id]=num;
               cnt[id]=1;
           }
           else {
               cnt[id]=num+1;
           }
       }
        fac(a0,prime[0]);
       fac(a1,prime[1]);
       for(auto x:prime[0]){
           int id=x.first;
           int num=x.second;
           if(num<prime[1][id]) {
               flag=0;
               break;
           }
           else if(num>prime[1][id]){
               if(!cnt[id]) {
                   xx[id]=prime[1][id];
                   cnt[id]=1;
               }
               else {
                   if(cnt[id]==1&&xx[id]!=prime[1][id]) {flag=0;break;}
                   else if(cnt[id]>1) {
                       if(cnt[id]>=prime[1][id]){
                           cnt[id]=1;
                           xx[id]=prime[1][id];
                       }
                       else {flag=0;break;}
                   }
               }
           }
           else {
               if(!cnt[id]) {flag=0;break;}
               else if(cnt[id]==1&&xx[id]<num) {flag=0;break;}
               else if(cnt[id]>1){
                   if(cnt[id]<num) {flag=0;break;}
                   else {
                       cnt[id]=cnt[id]-num;
                   }
               }
           }
       }
       ll ans=1;
       for(auto x:cnt){
           int num=x.second;
           //debug(x.first),debug(x.second);
           if(num!=0) ans=ans*num;
       }
       if(!flag) cout<<0<<endl;
       else cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
