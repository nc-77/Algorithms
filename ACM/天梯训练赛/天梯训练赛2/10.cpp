#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main()
{
	int n,ans=0;
	cin>>n;
	n--;
	int x;
	cin>>x;
	s.insert(x);
	while(n--)
	{
		
		cin>>x;
		if(s.upper_bound(x)!=s.end())
		{	
			s.erase(s.upper_bound(x));
			
		}
		s.insert(x);
	}
	cout<<s.size()<<endl;
}
