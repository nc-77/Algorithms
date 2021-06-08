#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
int tree[maxn][30],tot=0;
bool flag[maxn];
ll sum[maxn];
void add(string s)
{
	int root=0,id,len=s.size();
	for(int i=0;i<len;i++)
	{
		id=s[i]-'a';
		if(!tree[root][id]) tree[root][id]=++tot;
		sum[tree[root][id]]++;
		root=tree[root][id];
	}
	flag[root]=true;
}
ll find(string s)
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
{
	string s1,s2;
	while(getline(cin,s1))
	{	if(s1[0]=='\0') break;
		add(s1);
		//cout<<s1<<endl;
	}
	while(cin>>s2)
	{	
		cout<<find(s2)<<endl;
		
	}
	
}
