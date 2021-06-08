#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
bool check(string s)
{
    int sumx=0,cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='x') sumx++;
        if(s[i]=='l'&&sumx>=3) cnt++; 
    }
    if(cnt>=2) return false;
    return true;
}
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
       string xs(n,'x');
       string ls(n,'l');
       int ans=0;
       string res="";
    
       for(int i=n-1;i>=0;i--)
       {
           if(xs[i]==s[i]){
               res+=s[i];
                continue;
           } 
           string t=s.substr(0,i+1);
           reverse(t.begin(),t.end());
           string c=res+t;
           //debug(c);
           reverse(c.begin(),c.end());
           if(check(c)) {
               res+=s[i];
           }
           else res+=xs[i];
           
       }
       reverse(res.begin(),res.end());
        for(int i=0;i<n;i++)
        {
            if(res[i]!=s[i]) ans++;
        }
        int st=0;
        res="";
        for(int i=0;i<n;i++)
       {
           if(ls[i]==s[i]){
               res+=s[i];
                continue;
           } 
           string c=res+s.substr(i);
           if(check(c)) {
               res+=s[i];
           }
           else res+=ls[i];
          // debug(c);
           
       }
       
        for(int i=0;i<n;i++)
        {
            if(res[i]!=s[i]) st++;
        }
       cout<<min(st,ans)<<endl;
   }
   //system("pause");
   return 0;
}
