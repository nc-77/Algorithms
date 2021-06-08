#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
int tree[maxn][30],tot=0;
bool flag[maxn];
void add(string s)
{
	int root=0,id,len=s.size();k
	for(int i=0;i<len;i++)
	{
		id=s[i]-'a';
		if(!tree[root][id]) tree[root][id]=++tot;
		root=tree[root][id];
	}
	flag[root]=true;
}
bool find(string s)
{
	int root=0,id,len=s.size();
	for(int i=0;i<len;i++)
	{
		id=s[i]-'a';
		if(!tree[root][id]) return false;
		root=tree[root][id];
	}
	if(flag[root]) return true;
	else return false;
}

