#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn];
map<int,int>mp;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       mp.clear();
       for(int i=1;i<=n;i++) cin>>a[i];
       for(int i=1;i<=n;i++) cin>>b[i],b[i]-=a[i];
       int flag=1;
       for(int i=1;i<=n;i++)
       {
           if(b[i]==0) {mp[a[i]]++;continue;}
           
           if(b[i]>0&&mp[1]==0) flag=0;
           else if(b[i]<0&&mp[-1]==0) flag=0;
           mp[a[i]]++;
       }
       if(flag) puts("YES");
       else puts("NO");
   }
   //system("pause");
   return 0;
}
