#include<bits/stdc++.h>
using namespace std;
int a[1500],vis[1500];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	while(k--)
	{	int flag=1;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int num=1,now=1;
		stack<int>s;
		while(num!=n)
		{	
			if(a[now]==num)
			{
				num++;
				now++;
				continue;
			}
			else if(!s.empty()&&s.top()==num)
				{
					s.pop();
					num++;
					//cout<<num<<endl;
				}
			
			
				else if(s.size()<m)
				{	vis[a[now]]=1;
					//cout<<s.size()<<" "<<a[now]<<endl;
					s.push(a[now++]);
				}
				
				
			
			else  
				{
				flag=0;
				break;
				}
			
		}
		//cout<<num<<endl;
		if(flag) puts("YES");
		else puts("NO");
	}
}
