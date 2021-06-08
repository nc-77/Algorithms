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
vector<int>g[maxn];
int main()
{
    int m;
    cin>>m;
    init(1010);
    for(int i=0;i<m;i++)
    {
        int n;
        scanf("%d:",&n); 
        int x;
        for(int j=0;j<n;j++){
            cin>>x;
            g[x].push_back(i);
        }
    }
    for(int i=1;i<1001;i++){
        int len=g[i].size();
        for(int j=0;j<len-1;j++)
        {
            unite(g[i][j],g[i][j+1]);
        }
    }
    map<int,int>cnt;
    int sum=0;
    for(int i=0;i<m;i++){
        if(find(i)==i)  sum++;
        cnt[find(i)]++;
    }
    vector<int>ans;
    for(auto x:cnt){
           ans.push_back(x.second);
    }
    sort(ans.begin(),ans.end());
    cout<<sum<<endl;
    for(int i=sum-1;i>=0;i--){
        cout<<ans[i];
        if(i!=0) cout<<" ";
    }
    cout<<endl;
}
