#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n;
	char ch;
	cin>>n>>ch;
	int hs=(int)((double)n/2+0.5);
	for(int i=0;i<hs;i++)
	{
		for(int j=0;j<n;j++)
		cout<<ch;
		cout<<endl;
	}
}
