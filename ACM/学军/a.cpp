#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int n;
void w(int f,int sx,int sy)
{   cout<<sx<<" "<<sy<<endl;
    if(f==0)
    {   int x=sx,y=sy;
        for(int t=1;t<=n;t++)
        {   if(t%2)
            {
                cout<<--x<<" "<<y<<endl;
                for(int i=1;i<=n;i++) 
                {
                    if(i%2)cout<<++x<<" "<<++y<<endl;
                    else cout<<--x<<" "<<++y<<endl;
                }
                cout<<++x<<" "<<y<<endl;
            }
            else 
            {
                for(int i=1;i<n;i++) 
                {
                    if(i%2)cout<<--x<<" "<<--y<<endl;
                    else cout<<++x<<" "<<--y<<endl;
                }
                x--;y--;
                if(!(x==0&&y==1))cout<<x<<" "<<y<<endl;
            }
        }
    }
    else
    {
       int x=sx,y=sy;
        for(int t=1;t<n;t++)
        {   if(t%2)
            {   
                for(int i=1;i<=n;i++) 
                {
                    if(i%2)cout<<++x<<" "<<--y<<endl;
                    else cout<<--x<<" "<<--y<<endl;
                }
                x--;
                if(x>=0&&x<=n)cout<<x<<" "<<y<<endl;
            }
            else 
            {
                for(int i=1;i<=n;i++) 
                {
                    if(i%2)cout<<++x<<" "<<++y<<endl;
                    else cout<<--x<<" "<<++y<<endl;
                }
                x++;
                if(x<=n)cout<<x<<" "<<y<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        cout<<x<<" "<<--y<<endl;
    }
    
}
int main()
{
   
   cin>>n;
   cout<<n*(n+1)-1<<endl;
   if(n%2==0)
   {
       w(0,n,1);
   }
    else 
    {
        w(1,1,n+1);
    }
   //system("pause");
   return 0;
}
