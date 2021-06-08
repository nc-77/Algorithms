#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
   int t;
   cin>>t;
   for(int j=1;j<=t;j++)
   {
       int n,m;
       cin>>n>>m;
       for(int i=0;i<n;i++) cin>>a[i];
       sort(a,a+n,cmp);
      
        for(int i=0;i<m;i++)
        cout<<a[i]<<" ";
        cout<<endl;
   }
   //system("pause");
   return 0;
}
