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
       int n,m;
       cin>>n>>m;
        
        if(n%2==1)
        {
            if(m%2==1)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    if((i+j)%2==0) cout<<"B";
                    else cout<<"W";
                    cout<<endl;
                }
                    
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    if((i+j)%2==0||(i==n&&j==m)) cout<<"B";
                    else cout<<"W";
                    cout<<endl;
                }
            }
            
        }
        else
        {
           if(m%2==1)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    if((i+j)%2==0||(i==n&&j==m)) cout<<"B";
                    else cout<<"W";
                    cout<<endl;
                }
               
            }
            else
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    if((i+j)%2==0||(i==n&&j==1)) cout<<"B";
                    else cout<<"W";
                    cout<<endl;
                }
            }
        }
        
        
   }
   //system("pause");
   return 0;
}
