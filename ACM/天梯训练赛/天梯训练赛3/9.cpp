#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{	string name;
	int sum;
	int lb;
	double ave;
}stu[105];
map<int,int>mp[105];
bool cmp(node s1,node s2)
{
	if(s1.lb>s2.lb) return true;
	else if(s1.lb==s2.lb) return s1.ave<s2.ave;
	else return false;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string s;
		int x;
		cin>>stu[i].name>>stu[i].sum;
		for(int j=0;j<stu[i].sum;j++)
		{
			cin>>x;
			if(!mp[i][x])
			{
				stu[i].lb++;
				mp[i][x]=1;
			}
		}
		stu[i].ave=stu[i].sum*1.0/stu[i].lb;
	}
	sort(stu,stu+n,cmp);
	if(n>=3)
	{
		cout<<stu[0].name<<" "<<stu[1].name<<" "<<stu[2].name;
	}
	else if(n==2)
	cout<<stu[0].name<<" "<<stu[1].name<<"-";
	else if(n==1)
	cout<<stu[0].name<<" "<<"- -";
	
}
