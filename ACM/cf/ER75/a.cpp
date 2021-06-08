#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<char,int>mp1,mp2;
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       string s;
       cin>>s;
       mp1.clear();
       mp2.clear();
       int n=s.size();
       s[n]='.';
       int i=1,cnt=0;
       while(i<=n)
       {
           while(s[i]==s[i-1])
           {
               i++;
               cnt++;
           }
            {
               if((cnt+1)%2==1) mp1[s[i-1]]++;
               else mp2[s[i-1]]++;
               cnt=0;
               i++;
           }
       }
       for(int i=0;i<26;i++)
       {
           if(mp1[i+'a']) cout<<char(i+'a');
       }
       cout<<endl;
   }
   //system("pause");
   return 0;
}
