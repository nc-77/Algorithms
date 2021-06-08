#include<bits/stdc++.h>
using namespace std;
const int maxn=10050;
int tree[maxn][30],tot=0,maxx;
int sumt[maxn];
string ns;
char ans[maxn],t[maxn];
void add(string s,int x)
{
	int root=0,id,len=s.size();
	for(int i=0;i<len;i++)
	{
		id=s[i]-'a';
		if(!tree[root][id]) tree[root][id]=++tot;
		sumt[tree[root][id]]+=x;
		root=tree[root][id];
	}
}
void dfs(int st,int ed,int sum,int root)
{	if(st==ed)
	{
		if(sum>maxx)
		{
			maxx=sum;
			memset(ans,0,sizeof(ans));
			for(int i=0;i<ed;i++) ans[i]=t[i];
		}
		return;
	}
	int id=ns[st]-'0',bb,ss;
	if(id==7) bb='p'-'a',ss=4;
	else if(id==8) bb='t'-'a',ss=3;
	else if(id==9) bb='w'-'a',ss=4;
	else bb=id*3-6,ss=3;
	for(int i=bb;i<bb+ss;i++)
	{
		if(tree[root][i])
		{
			t[st]='a'+i;
			dfs(st+1,ed,sumt[tree[root][i]],tree[root][i]);
			t[st]=0;
		}
		 else continue;
	}
	return;
}
int main()
{
	int T,k;
	cin>>T;
	for(int k=1;k<=T;k++)
	{	
		memset(tree,0,sizeof(tree));
		memset(sumt,0,sizeof(sumt));
		tot=0;
		int n,p,q;
		cin>>n;
		string s;
		while(n--)
		{
			cin>>s>>p;
			add(s,p);
		}
		cin>>q;
		int flag=1;
		while(q--)
		{	
			cin>>s;
			ns.clear();
			if(flag)
			{
				cout<<"Scenario #"<<k<<":"<<endl;
				flag=0;
			}
			
			for(int i=0;i<s.size()-1;i++)
			{
				ns+=s[i];
				maxx=0;
				memset(ans,0,sizeof(ans));
				memset(t,0,sizeof(t));
				dfs(0,i+1,0,0);
				if(maxx==0) cout<<"MANUALLY";
				else
				{
					for(int j=0;j<i+1;j++)
					cout<<ans[j];
				}
				
				cout<<endl;
			}
			if(q!=0)cout<<endl;
		}
		cout<<endl<<endl;
	}
} 
