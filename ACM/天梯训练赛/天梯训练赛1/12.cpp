#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,s2;
bool judge(int x)
{	string s3;
	for(int i=0;i<=s.size()-x;i++)
	{
		 s3=s.substr(i,x);
		 if(s2.find(s3)<s2.size()) 
		 {
		 	//cout<<s3<<endl;
		 	return true;
		 }
	}
	return false;
}
int main()
{	
	
	getline(cin,s);
	int len=s.size();
	s2=s;
	reverse(s2.begin(),s2.end());
	int lp=1,up=len+1,mid;
	while(up-lp>1)
	{	
		mid=(up+lp)/2;
		//cout<<lp<<" "<<up<<" "<<mid<<endl;
		if(judge(mid))
		{
			lp=mid;
		}
		else 
		up=mid;
	}
	cout<<lp<<endl;
}
