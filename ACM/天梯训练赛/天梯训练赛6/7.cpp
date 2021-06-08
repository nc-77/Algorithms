#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[1010][1010];
int main()
{
	int n,m;
	cin>>n;
	getchar();
	string s;
	getline(cin,s);
	int cnt=0,flag=0;
	if(s.size()%n==0) m=s.size()/n;
	else m=s.size()/n+1;
	for(int i=1;i<=n;i++)
        a[i][1]=' ';
	for(int i=m;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{	if(cnt>=s.size())
			{
				flag=1;
				break;
			}
			
			a[j][i]=s[cnt++];
		}
		if(flag ) break;
	}
	//..cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<a[i][j];
		if(i!=n)
		cout<<endl;
	}	
}
