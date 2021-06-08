#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	string s[100];
	int i=1;
	while(cin>>s[i])
	{
		if(s[i]==".") break;
		i++;
	}
	if(i<=2) cout<<"Momo... No one is for you ..."<<endl;
	else if(i<=14) cout<<s[2]<<" is the only one for you..."<<endl;
	else cout<<s[2]<<" and "<<s[14]<<" are inviting you to dinner..."<<endl;
}
