#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int s0[maxn],s1[maxn];
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
       int x=0,y=0;
       for(int i=0;i<n;i++) {
           if((s[i]-'0')%2)  s1[++x]=s[i]-'0';
           else s0[++y]=s[i]-'0';
       }
       for(int i=x+1;i<=n+1;i++) s1[i]=inf;
       for(int i=y+1;i<=n+1;i++) s0[i]=inf;
       int i=1,j=1;
    
       while(i<=y||j<=x)
       {
           if(s0[i]<s1[j]){
               cout<<s0[i];
               i++;
           }
           else {
               cout<<s1[j];
               j++;
           }
           //if(s0[i]==inf&&s1[j]==inf) break;
       }
       cout<<endl;
   }
   //system("pause");
   return 0;
}
