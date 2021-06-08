#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
string s[105];
int nex[1050];
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
    while(i<slen&&j<plen)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else j=nex[j];
        
    }
    if(j==plen) return 1;
    return 0;
}
string ns[1050];
int main()
{
   int n;
   cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<s[i].size();j++)
        if(s[i][j]>='A'&&s[i][j]<='Z') s[i][j]=s[i][j]+'a'-'A';
        s[i]=' '+s[i]+' ';
    }
    getchar();
    string ss;
    getline(cin,ss);
    for(int i=0;i<ss.size();i++)
    if(ss[i]>='A'&&ss[i]<='Z') ss[i]=ss[i]+'a'-'A';
    int cnt=0;
    //debug(ss);
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]!='.') ns[cnt]+=ss[i];
        else cnt++;
    }
    //debug(cnt);
    int ans=0;
    for(int i=0;i<cnt;i++)
    {   ns[i]=' '+ns[i]+' ';
        //debug(ns[i]);
        for(int j=1;j<=n;j++)
        {   //debug(ns[i]);
            
            getnex(s[j]);
        if(kmp(ns[i],s[j])) ans++;
        }
        
    }
    cout<<ans<<endl;
   //system("pause");
   return 0;
}
