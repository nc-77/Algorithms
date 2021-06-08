#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       if(n<=3) {
           cout<<-1<<endl;
           continue;
       }
       
       for(int i=(n%2?n:n-1);i>0;i-=2)
       {
           cout<<i<<" ";
           if(i==1) cout<<4<<" "; 
       }
       for(int i=2;i<=n;i+=2)
       {
           if(i==4) continue;
           cout<<i<<" ";

       }
       
       cout<<endl;
   }
   //system("pause");
   return 0;
}
