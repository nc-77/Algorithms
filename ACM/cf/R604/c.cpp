#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
int a[maxn];
map<int,int>p;
 int n;
bool judge(int g,int s,int b)
{
    
    if(g>=s||g>=b) 
       return false;
       return true;
}
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
      
       cin>>n;
    p.clear();
       for(int i=1;i<=n;i++) cin>>a[i],p[a[i]]++;
       int num=unique(a+1,a+n+1)-a;
       if(n<10||num<3) 
       {
           cout<<"0 0 0"<<endl;
           continue;
       }
       int g=p[a[1]];
       int s=p[a[2]];
       int b=0;
       int last=2;
       for(int i=3;i<=num;i++)
       {
           if(g>=s) 
           {
               last=i;
                s=s+p[a[i]];
                
           }
           else break;
       }
       
       if(last+1<=num) b=p[a[last+1]];
       else
       {
       	cout<<"0 0 0"<<endl;
           continue;
	   }
       for(int i=last+2;i<=num;i++)
       {

           if(g+s+b+p[a[i]]<=n/2) 
           {
               b=b+p[a[i]];
           }
           else break;
       }
       
       if(judge(g,s,b)&&g+s+b<=n/2&&g&&s&&b) 
        cout<<g<<" "<<s<<" "<<b<<endl;
        else
        {
            cout<<"0 0 0"<<endl;
        }
        
   }
   //system("pause");
   return 0;
}
