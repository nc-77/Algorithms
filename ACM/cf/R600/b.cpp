#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],in[maxn];
map<int,int>mp;
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   int now=0;
   int flag=1;
   vector<int>g;
   int cnt=1;
   for(int i=1;i<=n;i++)
   {    if(a[i]>0&&mp[a[i]]) {flag=0;break;}
       if(a[i]>0&&!in[a[i]]) in[a[i]]=1,now++,mp[a[i]]=1;
       else if(a[i]>0&&in[a[i]])
       {
           flag=0;
           break;
       }
       if(a[i]<0)
       {
           if(in[-a[i]])
           {    
                   
                   in[-a[i]]=0;
               now--;
           }
           else if(!in[-a[i]]){
               flag=0;
               break;
           }
       }
        if(i!=n&&now==0) {cnt++;g.push_back(i);mp.clear();}
        //debug(now);
   }
   if(now) flag=0;

   else 
   {
       g.push_back(n);
       
   }
   if(flag) 
   {
       cout<<cnt<<endl;
        cout<<g[0]<<" ";
       for(int i=1;i<g.size();i++)
       {
           cout<<g[i]-g[i-1]<<" ";
       }
   }
   else puts("-1");
   //system("pause");
   return 0;
}
