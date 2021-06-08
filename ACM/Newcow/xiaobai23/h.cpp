#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],cnt[35];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {    set0(cnt);
       int m;
       cin>>m;
       for(int i=1;i<=m;i++) cin>>a[i],cnt[a[i]]++;
       int temp=2;
       int flag=0,last=0;
       for(int i=29;i>=0;i--)
       {
           if(cnt[i]>=temp)
           {
               cnt[i]=temp;
               flag=1;
               last=i;
               break;
           }
           else   temp=(temp-cnt[i])*2;
       }
       //for(int i=29;i>=0;i--) debug(cnt[i]);
       if(!flag) cout<<"impossible"<<endl;
       else 
       {
           for(int i=1;i<=m;i++)
           {
               if(cnt[a[i]]&&a[i]>=last)
               {
                   cout<<"1";
                   cnt[a[i]]--;
               }
               else cout<<"0";
           }
           cout<<endl;
       }
   }
   //system("pause");
   return 0;
}
