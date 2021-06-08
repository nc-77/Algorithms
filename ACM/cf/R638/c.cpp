#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[30];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
      
       sort(s.begin(),s.end());
      
      if(s[0]!=s[k-1]) {
         cout<<s[k-1];
      }
      else 
      {  cout<<s[0];
          if(s[k]!=s[n-1]) 
         {
            for(int i=k;i<n;i++) cout<<s[i];
         }
         else 
         {
            int lim=(n-k)/k+1;
         if((n-k)%k==0) lim--;
         for(int i=0;i<lim;i++) cout<<s[k];
         }
         
      }
     
      
      cout<<endl;
   } 
   //system("pause");
   return 0;
}
