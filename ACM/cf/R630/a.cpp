#include<iostream>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;

int x1,y1,x2,y2;
bool fun(int x,int y)
{
    if(x>=x1&&x<=x2&&y>=y1&&y<=y2) 
    return true;
    return false;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int a,b,c,d,x,y;
       cin>>a>>b>>c>>d;
       
       cin>>x>>y>>x1>>y1>>x2>>y2;
       int flag=1;
       int h=a-b,l=c-d;
       if(!fun(x-h,y-l)) flag=0;
       if(x==x1&&x==x2&&(a||b)) flag=0;
       if(y==y1&&y==y2&&(c||d)) flag=0;
       
       if(flag) puts("Yes");
       else puts("No");
   }
   //system("pause");
   return 0;
}
