#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int  n;
	cin>>n;
	 while(n--)
	 {	int flag=1;
	 	ll x,i;
	 	cin>>x;
	 	ll t=sqrt(x);
	 	for( i=2;i<=t;i++)
	 	{
	 		if(x%i==0)
	 		{
	 			flag=0;
	 			break;
			 }
		 }
		 if(t==1) flag=0;
		 if(flag) cout<<"Yes"<<endl;
		 else cout<<"No"<<endl;
	 }
}
