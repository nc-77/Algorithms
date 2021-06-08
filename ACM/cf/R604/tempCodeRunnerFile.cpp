#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int a,b,c,d;
   
   int flag=0;
   cin>>a>>b>>c>>d;
   int x=b-a,y=c-d;
   if(a==b&&a==0&&(abs(c-d)==0||abs(c-d)==1)) flag=1;
   if(c==d&&c==0&&(abs(a-b)==0||abs(a-b)==1)) flag=1;
   if(x>=0&&y>=0&&(abs(x-y)==0||abs(x-y)==1)) flag=1;
   if(flag) 
   {
       puts("YES");
    if(x==y)
    {
        for(int i=0;i<a;i++) cout<<0<<" "<<1<<" ";
        for(int i=0;i<x;i++) cout<<2<<" "<<1<<" ";
        for(int i=0;i<d;i++) cout<<2<<" "<<3<<" ";
    }
    else if(abs(x-y)==1)
    {
        if(x<y)
        {
            for(int i=0;i<a;i++) cout<<0<<" "<<1<<" ";
            for(int i=0;i<x;i++) cout<<2<<" "<<1<<" ";
        for(int i=0;i<d;i++) cout<<2<<" "<<3<<" ";
        cout<<2<<" ";
        }
        
        else
        {
            cout<<1<<" ";
            for(int i=0;i<a;i++) cout<<0<<" "<<1<<" ";
            for(int i=0;i<y;i++) cout<<2<<" "<<1<<" ";
        for(int i=0;i<d;i++) cout<<2<<" "<<3<<" ";
        }
        
    }
    
    
   }
   else puts("NO");
   //system("pause");
   return 0;
}
