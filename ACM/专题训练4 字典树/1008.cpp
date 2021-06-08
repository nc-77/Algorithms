#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+10;
int tot=0;
int tree[maxn][27],sid[maxn];
int sum[maxn];
void add(string s,int m)
{
	int root=0,id,len=s.size();
	for(int i=0;i<len;i++)
	{
		id=s[i]-'a';
		if(!tree[root][id]) 
		{
			tree[root][id]=++tot;
			sid[tree[root][id]]=m;
			sum[tree[root][id]]=1;
		}
		if(sid[tree[root][id]]!=m)
		{
			sum[tree[root][id]]++;
			sid[tree[root][id]]=m;
		}
		root=tree[root][id];
	}
	
}
int find(string s)
{
	int root=0,id,len=s.size();
	for(int i=0;i<len;i++)
	{	
		id=s[i]-'a';
		if(!tree[root][id]) return 0;
		root=tree[root][id];
	}
	return sum[root];
}
int main()
{	ios::sync_with_stdio(false);
	string s;
	int p,q;
	cin>>p;
	for(int i=1;i<=p;i++)
	{
		cin>>s;
		int len=s.size();
		for(int j=0;j<len;j++)
			{
				add(s.substr(j),i);
				//cout<<s.substr(j)<<endl;
			}
	}
	cin>>q;
	while(q--)
	{
		cin>>s;
		cout<<find(s)<<endl;
	}
}
