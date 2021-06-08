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
       int n;
       cin>>n;
       string s;
       cin>>s;
       double nx=0.5,ny=0.5,x=0,y=0;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='H') 
           {
               x+=nx/2;
               y+=ny/2;
               nx/=2,ny/=2;
               nx+=0.5;
           }
           if(s[i]=='M') 
           {
               x+=nx/2;
               y+=ny/2;
               nx/=2,ny/=2;
               ny+=0.5;
           }
       }
       if(x>y) cout<<"H"<<endl;
       else if(x==y) cout<<"HM"<<endl;
       else cout<<"M"<<endl;
   }
   //system("pause");
   return 0;
}
