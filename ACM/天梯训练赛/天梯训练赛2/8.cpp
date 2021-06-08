#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char ch;
	cin>>n>>ch;
	string s;
	getchar();
	getline(cin,s);
	int len=s.size();
	//cout<<len<<" "<<n<<endl;
	if(len>=n) 
	{	
		for(int i=len-n;i<len;i++)
	cout<<s[i];
	}
	
	else
	{
		for(int i=1;i<=n-len;i++)
		cout<<ch;
		cout<<s;
	}
	
}
