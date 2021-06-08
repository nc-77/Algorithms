#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s;
	int cj;
}stu[10000+10];
bool cmp(node s1,node s2)
{
	if(s1.cj>s2.cj) return true;
	else if(s1.cj==s2.cj) return s1.s<s2.s;
	return false;
}
int main()
{
	int n,g,k,sum=0;
	cin>>n>>g>>k;
	for(int i=0;i<n;i++)
	{
		
		cin>>stu[i].s>>stu[i].cj;
		if(stu[i].cj>=g&&stu[i].cj<=100) sum+=50;
		if(stu[i].cj>=60&&stu[i].cj<g) sum+=20;
	}
	sort(stu,stu+n,cmp);
	cout<<sum<<endl;
	int num=1,cnt=0;
	cout<<num<<" "<<stu[0].s<<" "<<stu[0].cj<<endl;
	for(int i=1;;i++)
	{	if(num>k) break;
		
			if(stu[i].cj!=stu[i-1].cj)
			{
			
				num+=cnt;
				num++;
					cnt=0;
			}
			else cnt++;
		
		if(num>k) break;
		
		cout<<num<<" "<<stu[i].s<<" "<<stu[i].cj<<endl;
	
	}
}
