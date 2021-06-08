#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g;
ll mpow(int x){
    int res=1;
    for(int i=1;i<=x;i++)
    res*=10;
    return res;
}
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int cnt=0;
       g.clear();
       while(n)
       {
           
           if(n%10!=0)
           {
               //debug(n);
           g.push_back(n%10*mpow(cnt));
           }
          cnt++;
           n=n/10;
       }
       cout<<g.size()<<endl;
       for(int i=0;i<g.size();i++)
       cout<<g[i]<<" ";
       cout<<endl;
   }
   //system("pause");
   return 0;
}
