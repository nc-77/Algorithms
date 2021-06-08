#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
int par[maxn];
void init(int n){
	for(int i=1;i<=n;i++) par[i]=i;
} 
int find(int x)
{
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	par[x]=y;
}
bool same(int x,int y){
	return find(x)==find(y);	
}
int main()
{
    int m,n;
    cin>>n>>m;
    init(n);
    for(int i=0;i<m;i++)
    {
        int people;
        cin>>people;
        int x=-1,y=-1;
        for(int i=0;i<people;i++)
        {
            cin>>x;
            if(x!=-1&&y!=-1) unite(x,y);
            y=x;
        }
    }
    
    map<int,int>cnt;
    int ans=0;
    for(int i=1;i<=n;i++){
        cnt[find(i)]++;
        ans=max(ans,cnt[find(i)]);
    }
    cout<<ans<<endl;
}
