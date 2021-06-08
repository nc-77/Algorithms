#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[150];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
        set0(a);
        for(int i=1;i<=n;i++) cin>>a[i];
        int x=0,y=0,z=0,cnt=0;
        for(int i=1;i<=n;i++) 
        {
            if(a[i]%2==0) 
            {
                x=i;
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]%2==1&&cnt==0)
            {
                y=i;
                cnt++;
            }
            else if(a[i]%2==1&&cnt==1)
            {
                z=i;
                cnt++;
            }
            if(cnt==2) break;
        }
        if(x) 
        {
            puts("1");
            cout<<x<<endl;
        }
        else if(cnt==2)
        {
            puts("2");
            cout<<y<<" "<<z<<endl;
        }
        else puts("-1");
   }
   //system("pause");
   return 0;
}

