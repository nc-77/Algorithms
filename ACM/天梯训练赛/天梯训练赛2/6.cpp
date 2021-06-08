#include<bits/stdc++.h>
using namespace std;
struct node
{
	int sx;
	string name;
}stu[100];
int vis[100];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i].sx>>stu[i].name;
		
	}
	for(int i=0;i<n/2;i++)
	{
		for(int j=n-1;j>=n/2;j--)
		{
			if(stu[j].sx!=stu[i].sx&&!vis[j])
			{
				stu[i].name+=" ";
				stu[i].name+=stu[j].name;
				vis[j]=1;
				vis[i]=1;
				//cout<<stu[i].name<<endl;
				break;
			}
		}
	}
	for(int i=0;i<n/2;i++)
	{
		cout<<stu[i].name<<endl;
	}
}
