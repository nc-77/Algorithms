#include<bits/stdc++.h>
using namespace std;
int main()
{	int flag1=1,flag2=1,a=0,b=0;
	string s1,s2;
	cin>>s1;
	getchar();
	getline(cin,s2);
	if(s1.size()>4) flag1=0;
	else
	{
		for(int i=0;i<s1.size();i++)
		{
		if(s1[i]<'0'||s1[i]>'9') 
		{
			flag1=0;
			break;
		}
		a=a*10+s1[i]-'0';
		if(a>1000||a<1)
		{
			flag1=0;
			break;
		}
		}
	}
	if(s2.size()>4) flag2=0;
	else
	{
		for(int i=0;i<s2.size();i++)
		{
		if(s2[i]<'0'||s2[i]>'9') 
		{
			flag2=0;
			break;
		}
		b=b*10+s2[i]-'0';
		if(b>1000||b<1)
		{
			flag2=0;
			break;
		}
		}
	}
	if(flag1==0&&flag2==0) cout<<"? + ? = ?"<<endl;
	if(flag1==0&&flag2) cout<<"? + "<<b<<" = ?"<<endl;
	if(flag1&&flag2==0) cout<<a<<" + ? = ?"<<endl;
	if(flag1&&flag2) cout<<a<<" + "<<b<<" = "<<a+b<<endl;
}
