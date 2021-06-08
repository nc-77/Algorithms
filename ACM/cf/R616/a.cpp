#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	int num=0;
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
		{	s[i]=s[i]-'0';
			if(s[i]%2==1) 
			{
				num++;
				a[num]=s[i];
			}
			if(num>=2)
			break;
		}
		if(num<2) puts("-1");
		else cout<<a[1]<<a[2]<<endl;
	}
}
