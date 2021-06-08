#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
int tree[maxn][30],tot=0;
bool flag[maxn];
void add(string s)
{
	int root=0,id,len=s.size();
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
int main()
{	ios::sync_with_stdio(false);
	string s[50000+10];
	int num=0;
	while(cin>>s[num])
	{
		add(s[num]);
		num++;
	 } 
	 //cout<<"here"<<endl;
	 for(int i=0;i<num;i++)
	 {	int len=s[i].size();
	 	for(int j=1;j<len;j++)
	 	{
	 		string s1=s[i].substr(0,j);
	 		string s2=s[i].substr(j);
	 		if(find(s1)&&find(s2))
	 		{
	 			cout<<s[i]<<endl;
	 			break;
			 }
		 }
	 }
}
