#include<bits/stdc++.h>
using namespace std;
vector<int>kid[100000+10];
int r[100000+10];
int b[100000+10];
struct node
{
	int id;
	int step;
}cur,nex;
void bfs(int st)
{
	queue<node>que;
	cur.id=st;
	cur.step=1;
	que.push(cur);
	while(!que.empty())
	{	cur=que.front();
		que.pop();
		//cout<<cur.id<<endl;
		//cout<<kid[cur.id].size()<<endl;
		for(int i=0;i<kid[cur.id].size();i++)
		{	
			nex.id=kid[cur.id][i];
			nex.step=cur.step+1;
			que.push(nex);
			r[nex.id]=r[cur.id]+1;
			//cout<<nex.id<<" "<<r[nex.id]<<endl;
		}
		
	}
	cout<<cur.step<<endl;
	
}
int main()
{
	int n,st;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x==-1)
		{
			r[i]=1;
			st=i;
		}
		else 
		kid[x].push_back(i);
	}
	bfs(st);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(r[i]==cur.step){
			b[cnt++]=i;
		}
	}
	for(int i=0;i<cnt;i++)
	{
		if(i!=cnt-1){
			cout<<b[i]<<" ";
		}
		else{
			cout<<b[i]<<endl;
		}
	}
	
}
