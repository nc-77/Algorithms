#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--)
	{	int flag=0,num=0,k;
		string s;
		//cin>>s;
		getline(cin,s);
		int len=s.size();
		for(int i=0;i<len;i++)
		{
			if(s[i]==','&&s[i-1]=='g'&&s[i-2]=='n'&&s[i-3]=='o')
			{
				if(s[len-2]=='g'&&s[len-3]=='n'&&s[len-4]=='o')
				flag=1;
			 } 
		 } 
		 if(!flag) cout<<"Skipped"<<endl;
		 else 
		{
			for(int i=len-1;i>=0;i--)
			{
				if(s[i]==' ') num++;
				if(num==3) 
				{
					k=i;
					break;
				}
			}
			//cout<<s<<endl;
			for(int i=0;i<k;i++)
			{
				cout<<s[i];
			}
			cout<<" qiao ben zhong."<<endl;
		}
	}
}
