#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int y,n;
	cin>>y>>n;
	for(int i=y;;i++)
	{   set<int>s;
		 int a=i%10;
		s.insert(a);
		 int b=i/10%10;
		  s.insert(b);
		int c=i/100%10;
		 s.insert(c);
		 int d=i/1000;
		  s.insert(d);
		
		int ans=s.size();
		if(ans==n)
		{
			cout<<i-y<<" ";
			printf("%04d",i);
			break;
		}
	}
 } 
