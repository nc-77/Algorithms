#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int nex[maxn];
int getnex(string s)
{
    int len=s.size();
    for(int  i=0;i<=len;i++) nex[i]=0;
    nex[0]=-1;
    int j=0,k=-1;
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
    
    return nex[len];
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string s;
       cin>>s;
       int len=s.size();
       int st=0,ed=len-1;
        while(st<ed) if(s[st]==s[ed]) st++,ed--;else break;
        string mids=s.substr(st,ed-st+1);
        string rev=mids;reverse(rev.begin(),rev.end());
        string qz,hz;
         qz=mids+"*"+rev;
         int tt=getnex(qz);
         hz=rev+"*"+mids;
         int mm=getnex(hz);
         if(tt>=mm)
          mids=mids.substr(0,tt);
          else mids=rev.substr(0,mm);
            for(int i=0;i<st;i++)
            cout<<s[i];
            cout<<mids;
            for(int i=st-1;i>=0;i--)
            cout<<s[i];
            cout<<endl;
        
   }
   //system("pause");
   return 0;
}
