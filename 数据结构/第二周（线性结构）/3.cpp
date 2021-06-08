#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
struct node
{
    int x,y;
    bool operator <(node & t){
        return y>t.y;
    }
};
vector<node>g1,g2;
void read(vector<node>& g,int n)
{
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g.push_back({x,y});
    }
}
void print(vector<node>&g)
{
    int cnt=0;
    for(auto it=g.begin();it!=g.end();)
    {
        if(!(*it).x) it=g.erase(it);
        else it++;
    }
    for(int i=0;i<g.size();i++)
    {
        cnt++;
        cout<<g[i].x<<" "<<g[i].y<<(i==g.size()-1?"":" ");
    }
    if(!cnt) cout<<0<<" "<<0;
    cout<<endl;
}
int main()
{
   int n,m;
    cin>>n;
    read(g1,n);
    cin>>m;
    read(g2,m);
    int p=0,q=0;
    vector<node>g4,g3;
    while(p<n&&q<m)
    {
        if(g1[p].y>g2[q].y){
            g4.push_back(g1[p]);
            p++;
        }
        else if(g1[p].y==g2[q].y){
            g4.push_back({g1[p].x+g2[q].x,g1[p].y});
            p++,q++;
        }
        else {
            g4.push_back(g2[q]);
            q++;
        }
    }
    if(p<n){
        for(int i=p;i<n;i++)
        g4.push_back(g1[p]);
    }
    else{
        for(int i=q;i<m;i++)
        g4.push_back(g2[q]);
    }
    map<int,int>mp;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            mp[g1[i].y+g2[j].y]+=g1[i].x*g2[j].x;
        }
    for(auto x:mp){
        g3.push_back({x.second,x.first});
    }
    sort(g3.begin(),g3.end());
    print(g3);
    print(g4);
   //system("pause");
   return 0;
}
