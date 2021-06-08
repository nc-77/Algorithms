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
       string s;
       cin>>s;
       int n=s.size();
       int f0=0,f1=0;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='0') f0++;
           else f1++;
       }
       if(f0==n||f1==n) cout<<s;
       else 
       {
           if(s[0]=='1')
           for(int i=0;i<n;i++) cout<<10;
           else 
           for(int i=0;i<n;i++) cout<<0<<1;
       } 
       cout<<endl;
   }
   //system("pause");
   return 0;
}
