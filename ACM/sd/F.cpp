#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct date
{
    int m,d;
}ma[105],fa[105];
int magetday(int year)
{   int rn=0,ans=0,day;
    for(int i=1900;i<=year;i++)
	{
	   if((i%400==0)||((i%100!=0)&&(i%4==0)))rn+=1;
    }
	day=(((year-1899)*365+rn)-(31+30+31+31+30+31+30+31))%7;
     ans=14-day;
    return ans;
}
int fagetday(int year)
{   int rn=0,ans=0,day;
    for(int i=1900;i<=year;i++)
	{
	   if((i%400==0)||((i%100!=0)&&(i%4==0)))rn+=1;
    }
	day=(((year-1899)*365+rn)-(30+31+31+30+31+30+31))%7;
	if(day==7)ans=14;
	else ans=14-day;
    return ans+7;
}
int main()
{
   for(int i=0;i<=101;i++)
   {
       ma[i].m=5;
       ma[i].d=magetday(i+2000);
       fa[i].m=6;
       fa[i].d=fagetday(i+2000);
   }
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       int y,m,d;
       cin>>y>>m>>d;
       y=y-2000;
       if((m<ma[y].m||(m==ma[y].m&&d<ma[y].d)))
       {
           printf("Mother's Day: May ");
           cout<<ma[y].d;
           if(ma[y].d>10&&ma[y].d<=20) cout<<"th, ";
            else if(ma[y].d%10==1) cout<<"st, ";
            else if(ma[y].d%10==2) cout<<"nd, ";
            else if(ma[y].d%10==3) cout<<"rd, ";
            else cout<<"th, ";
            cout<<y+2000<<endl;
       }
       else if((m<fa[y].m||(m==fa[y].m&&d<fa[y].d)))
       {
           printf("Father's Day: June ");
           cout<<fa[y].d;
           if(fa[y].d>10&&fa[y].d<=20) cout<<"th, ";
            else if(fa[y].d%10==1) cout<<"st, ";
            else if(fa[y].d%10==2) cout<<"nd, ";
            else if(fa[y].d%10==3) cout<<"rd, ";
            else cout<<"th, ";
            cout<<y+2000<<endl;
       }
       else 
       {
           y=y+1;
           printf("Mother's Day: May ");
           cout<<ma[y].d;
           if(ma[y].d>10&&ma[y].d<=20) cout<<"th, ";
            else if(ma[y].d%10==1) cout<<"st, ";
            else if(ma[y].d%10==2) cout<<"nd, ";
            else if(ma[y].d%10==3) cout<<"rd, ";
            else cout<<"th, ";
            cout<<y+2000<<endl;
       }
   }
   //system("pause");
   return 0;
}
