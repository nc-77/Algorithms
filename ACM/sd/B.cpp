#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct node
{
    int s,num;
    double t;
}a[maxn];
bool cmp(node x,node y)
{
    if(x.s>y.s) return true;
    else if(x.s==y.s)
    {
        if(x.t>y.t) return true;
        else if(x.t==y.t) return x.num<y.num;
        else return false; 
    }
    return false;
}
int main()
{
   int n;
   cin>>n;
   int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int s,num;
        double t;
        cin>>s>>num>>t;
        if(t>=38.0) a[++cnt].s=s,a[cnt].num=num,a[cnt].t=t;
    }
    sort(a+1,a+cnt+1,cmp);
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i].s<<" "<<a[i].num<<" ";
        printf("%.1f\n",a[i].t);
    }
   //system("pause");
   return 0;
}
