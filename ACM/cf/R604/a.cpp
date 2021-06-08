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
       string s;
       cin>>s;
       int n=s.size();
       s="a"+s;
       
       for(int i=1;i<n;i++)
       {
           if(s[i]=='?')
           {
               if(s[i-1]!='?'&&s[i+1]!='?')
               {
                   if(s[i-1]=='a'&&s[i+1]=='a')
                    s[i]='b';
                    if(s[i-1]=='b'&&s[i+1]=='b')
                    s[i]='a';
                    if(s[i-1]=='c'&&s[i-1]=='c')
                    s[i]='a';
                    if(s[i-1]=='a'&&s[i+1]=='b'||s[i-1]=='b'&&s[i+1]=='a')
                    s[i]='c';
                    if(s[i-1]=='a'&&s[i+1]=='c'||s[i-1]=='c'&&s[i+1]=='a')
                    s[i]='b';
                    if(s[i-1]=='b'&&s[i+1]=='c'||s[i-1]=='c'&&s[i+1]=='b')
                    s[i]='a';
               }
               else
               {
                   if(s[i-1]=='a')
                    s[i]='b';
                    if(s[i-1]=='b')
                    s[i]='a';
                    if(s[i-1]=='c')
                    s[i]='a';
               }
               
               
               
           }
       }
       if(s[n]=='?') 
       {
           if(s[n-1]=='a') s[n]='b';
            if(s[n-1]=='b') s[n]='a';
             if(s[n-1]=='c') s[n]='b';
       }
       int flag=1;
    for(int i=2;i<=n;i++) if(s[i]==s[i-1]) flag=0;
    if(flag) for(int i=1;i<=n;i++) cout<<s[i];
    else cout<<"-1";
    cout<<endl;
   }
   //system("pause");
   return 0;
}
