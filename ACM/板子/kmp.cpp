#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int nex[maxn],cnt,ans[maxn];//最长前缀后缀
void getnex(string s)
{
    int len=s.size();
    set0(nex);
    nex[0]=-1;
    int k=-1,j=0;
    while(j<len)
    {   
        if(k==-1||s[j]==s[k]) 
        {
            k++;
            j++;
            nex[j]=k;
        }
        else k=nex[k];
    }
}
int kmp(string s,string p)
{   int i=0,j=0;
    int slen=s.size(),plen=p.size();
    while(i<slen)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else j=nex[j];
        if(j==plen) ans[cnt++]=i-j+1,j=0,i--;
    }
    return 0;
}
int main()
{
   string s1,s2;
   cin>>s1>>s2;
   getnex(s2);
   kmp(s1,s2);
   for(int i=0;i<cnt;i++) cout<<ans[i]<<endl;
   cout<<nex[1];
   for(int i=2;i<=s2.size();i++) cout<<" "<<nex[i];
   return 0;
}
