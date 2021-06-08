#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
 int n;
struct node
{
    double x,y;
}s[100000+10];
double jl(double x)
{   double ans=0,t;
    for(int i=0;i<n;i++)
    {
        t=sqrt((x-s[i].x)*(x-s[i].x)+s[i].y*s[i].y);
        ans=max(ans,t);
    }
    return ans;
}
int main()
{

    double l=10000+10,r=-10010;
    cin>>n;
    double my=0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].x>>s[i].y;
        if(s[i].x<l) l=s[i].x;
        if(s[i].x>r) r=s[i].x;
        if(fabs(s[i].y)>=my) my=fabs(s[i].y);
    }
    //debug(l);
    //debug(r);
    if(l==r)
    {
        printf("%.6f",my);
        return 0;
    }
    double ans=inf;
    l=0,r=1e6;
    while(r-l>1e-30)
    {
        double mid=(r+l)/2;
        debug(mid);
        if(jl(mid))
        {

            r=mid;
        }
        else l=mid;
    }
    printf("%.6f",l);
}
