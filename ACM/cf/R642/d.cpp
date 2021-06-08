#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
 int n,ans[maxn];
 struct node
 {
     int sum,l,r;
     bool operator < (const node & a) const
	{
	    if(sum!=a.sum)	return sum<a.sum;
        else return l>a.l;
	}
 };
 
void bfs()
{
    priority_queue<node >que;
    que.push({n,1,n});
    int cnt=0;
    while(!que.empty())
    {
        node cur=que.top();
        que.pop();
        int l=cur.l,r=cur.r;
        int mid=(l+r)/2;
        //debug(l),debug(r),debug(cnt+1);
        ans[mid]=++cnt;
        node nex,ne;
        nex.l=l;
        nex.r=mid-1;
        nex.sum=nex.r-nex.l+1;
        ne.l=mid+1;
        ne.r=r;
        ne.sum=ne.r-ne.l+1;
        if(cnt==n) break;
        if(ne.l<=ne.r)que.push(ne);
        if(nex.l<=nex.r)que.push(nex);
    }

}
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
    while(t--)
    {
        cin>>n;
   bfs();
   for(int i=1;i<=n;i++)
   cout<<ans[i]<<" ";
   cout<<endl;
    }
    
   
   //system("pause");
   return 0;
}
