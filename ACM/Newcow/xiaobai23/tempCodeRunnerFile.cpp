#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
signed main()
{   int t;
    cin>>t;
    while(t--)
    {   
        ll p,x=1;
        cin>>p;
       while(1)
       {
           if(p%x==0) p=p/x;
           x++;
           if(x>p) break;
       }
        //debug(p);
        x--;
    if(p!=1)
    {
        for(int i=x+1;;i++)
    {
        if(i%p==0) 
        {
            x=i;
            break;
        }
    }
    }
    
    cout<<x<<endl;
    
    }
    
   
   //system("pause");
   return 0;
}
