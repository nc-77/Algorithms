#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int k,num=1;
	cin>>k;
	string s;
	k++;
	while(cin>>s)
	{	
		if(s=="End") break;
		//cout<<s<<endl;
		if(num%k==0)
		cout<<s<<endl;
		else
		{
			if(s[0]=='C')
			cout<<"Bu"<<endl;
			else if(s[0]=='J')
			cout<<"ChuiZi"<<endl;
			else 
			cout<<"JianDao"<<endl;
		}
		num++;
		s.clear();
	}
}
