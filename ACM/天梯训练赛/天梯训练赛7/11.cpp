#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1005;
int head[maxn],sz=0;
map<int,int>num;
void push(int x)
{
	int i=sz++;
	while(i>0)
	{
		int p=(i-1)/2;
		if(head[p]<=x) break;
		head[i]=head[p];
		i=p;
	}
	head[i]=x;

}
int main()
{
	int n,m;
	cin>>n>>m;
	getchar();
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		push(x);
		
	}
	getchar();
	for(int i=0;i<n;i++)
	{
		num[head[i]]=i;
		//cout<<head[i]<<" "<<i<<endl;
	}
	while(m--)
	{
		int a=0,b=0,flag=0,f=0;
		int cnt=0;
		int ss[10]={0};
		string s;
		
		getline(cin,s);
		s+=" ";
		for(int i=0;i<s.size();i++)
		{	
			if((s[i]-'0')>=0&&(s[i]-'0')<=9)
			{	
				a=a*10+(s[i]-'0');
				f=1;
			}
			if(s[i]=='-') flag=1;
			if(s[i]==' '&&f)
			{	if(flag) ss[cnt++]=-a;
				else ss[cnt++]=a;
				flag=0;
				f=0;
				
				a=0;
			}
		}
		a=ss[0],b=ss[1];
		//cout<<a<<" "<<b<<endl;
		if(s.find("root")!=string::npos) 
		{
			if(num[a]==0)  puts("T");
			else puts("F");
		 } 
		 else if(s.find("sibling")!=string::npos) 
		{
			if((num[b]-1)/2==(num[a]-1)/2)  puts("T");
			else puts("F");
		 } 
		 else if(s.find("parent")!=string::npos) 
		{
			if(num[a]==(num[b]-1)/2)  puts("T");
			else puts("F");
		 } 
		 else if(s.find("child")!=string::npos) 
		{
			if(num[b]==(num[a]-1)/2)  puts("T");
			else puts("F");
		 } 
	}
	
}
