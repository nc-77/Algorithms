#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],m;
map<int,int>prime;
map<int,int>mp;
int ans[maxn];
void fac(int n,int id)
{   int flag=0;
    int t=n,tt=n;
    int x=sqrt(t);
    for(int i=2;i<=x;i++)
    { 
          while(t%i==0)
        {   //debug(t),debug(prime[i]);
            if(prime[i])
            {
                ans[id]=mp[i];
                flag=1;
                break;
            } 
            else{
                prime[i]=1;
                mp[i]=++m;
                ans[id]=m;
                flag=1;
                break;
            }     
            //prime[i]++;
            t=t/i;
        }
        if(flag) break;
    }
    
    
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {    m=0;
       int n;
       cin>>n;
       prime.clear();
       mp.clear();
       for(int i=1;i<=n;i++) cin>>a[i];
       
       for(int i=1;i<=n;i++)
       {
            fac(a[i],i);
       }
       cout<<m<<endl;
       for(int i=1;i<=n;i++) 
       cout<<ans[i]<<" ";
       cout<<endl;
   }
   //system("pause");
   return 0;
}
