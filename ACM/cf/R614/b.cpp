#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n,ans=0,i;
	cin>>n;
	for( i=1;i<=n;i++)
	ans+=1/i;
	cout<<ans<<endl;
}
