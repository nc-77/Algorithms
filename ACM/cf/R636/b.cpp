#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       ll n;
       cin>>n;
       if(n/2%2) 
       {
           cout<<"NO"<<endl;
           continue;
       }
       else 
       {
           puts("YES");
           for(int i=2;i<=n;i+=2)
            cout<<i<<" ";
            for(int i=1;i<=n+1;i+=2)
            {
                if(i==n/2+1) continue;
                cout<<i<<" ";
            }
        cout<<endl;
       }
   }
   //system("pause");
   return 0;
}
