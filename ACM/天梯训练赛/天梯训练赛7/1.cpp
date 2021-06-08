#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	string s;
	cin>>s;
	int len=s.size();
	int sum=0,f1=0,f2=0;
	if(s[0]=='-') f2=1;
	if((s[len-1]-'0')%2==0) f1=1;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='2') sum++;
		
	}
	if(f2) len--;
	//cout<<sum<<" "<<len;
	double ans=sum*1.0/len;
	if(f1) ans=ans*2;
	if(f2) ans=ans*1.5;
	ans=ans*100;
	printf("%.2f",ans);
	cout<<"%"<<endl;
 } 
