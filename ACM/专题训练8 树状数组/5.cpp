#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define PII pair<int,int>
using namespace std;
const int maxn=4e4+1;
int bit[maxn],ans[maxn];
int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=maxn)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
int main()
{
    int n;
    while(cin>>n)
    {
        set0(bit);
        set0(ans);
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            x++,y++;
            ans[sum(x)]++;
            add(x,1);
        }

        for(int i=0;i<n;i++)
        {
            cout<<ans[i]<<endl;
        }
    }

}
