#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100+10;
int a[maxn][maxn];
struct node
{
	int id,x;
}num[maxn];
bool cmp (node x,node y)
{
	return x.x>y.x;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {	set0(a),set0(num);
    	int n;
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	cin>>num[i].x,num[i].id=i;
    	sort(num+1,num+n+1,cmp);
    	int flag=1;
    	for(int i=1;i<=n;i++)
    	{	int cnt=0;
    		int k=num[i].x;
    		if(k==0) continue;
    		sort(num+i+1,num+n+1,cmp);
    		for(int j=i+1;j<=n;j++)
    		{	if(num[j].x>0)
	    		{
	    			a[num[i].id][num[j].id]=a[num[j].id][num[i].id]=1;
    				num[j].x--;
    				cnt++;
    				if(cnt==k) break;
				}
			}
			if(cnt<k) 
				{
					flag=0;
					break;
				}
			
		}
		if(flag)
		{	puts("YES");
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
				{
					cout<<a[i][j];
					if(j==n) cout<<endl;
					else cout<<" ";
				}
		}
		else puts("NO");
		cout<<endl;
	}
}

