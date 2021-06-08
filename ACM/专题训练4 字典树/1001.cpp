#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100;
int tree[maxn][2],tot=0,vis[maxn];
void add(string s,int num)
{
	int root=0,id,len=s.size();

	for(int i=0;i<len;i++)
	{
		id=s[i]-'0';
		if(!tree[root][id]) tree[root][id]=++tot;
		root=tree[root][id];

	}
	vis[num]=root;

}

int main()
{	int num=0,cnt=0,flag=0;
	string s[10];
	while(cin>>s[num])
	{	
		if(s[num]=="9")
		{	cnt++;
			flag=0;
			for(int i=0;i<num;i++)
			{	
				if(tree[vis[i]][0]||tree[vis[i]][1])
				{
					flag=1;
					break;
				}
			}
			if(flag) printf("Set %d is not immediately decodable\n",cnt);
			else printf("Set %d is immediately decodable\n",cnt);
			num=tot=0;
			memset(tree,0,sizeof(tree));
			memset(vis,0,sizeof(vis));
		}
		else 
		{
			add(s[num],num);
			num++;
		}
	}
}
