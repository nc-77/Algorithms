#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
map<int,int>mp;
set<int>s;
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       s.clear();
       int mx=0;
       for(int i=1;i<=n;i++){
           cin>>a[i];
           mp[a[i]]=1;
           mx=max(mx,a[i]);
            s.insert(a[i]);
       }
       int flag;
       for(int k=1;k<=1025;k++){
            flag=1;
            set<int>st;
           for(int i=1;i<=n;i++){
               int x=a[i]^k;
               st.insert(x);
           }
           if(st==s) flag=1;
           else flag=0;
           if(flag) {
               cout<<k<<endl;
               break;
           }
       }
       if(!flag) cout<<-1<<endl; 
   }
   //system("pause");
   return 0;
}
