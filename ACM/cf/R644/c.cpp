#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int x=0,y=0;
       for(int i=1;i<=n;i++) 
       {
           cin>>a[i];
           if(a[i]%2) x++;
           else y++;
       }
       sort(a+1,a+n+1);
       int f=0;
       for(int i=1;i<n;i++)
       {
           if(a[i]==a[i+1]-1) f++;
       }
       if(x%2==0&&y%2==0)
       {
           puts("YES");
       }
       else 
       {
           if(f) puts("YES");
           else puts("NO");
       }
       
   }
   //system("pause");
   return 0;
}
