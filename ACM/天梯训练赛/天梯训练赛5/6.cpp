#include<bits/stdc++.h>
using namespace std;
char a[105][105],b[105][105];
int main()
{	
	char ch;
	int n,flag=1;
	    cin>>ch;
    getchar();
    cin>>n;
    getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			 a[i][j]=getchar(); 
			
		}
		 getchar();  
		//cout<<a[i]<<endl;
	}
		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
	b[i][j]=a[n-i+1][n-j+1];
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		cout<<a[i][j];
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]!=b[i][j])
			flag=0;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]!=' ') b[i][j]=ch;
		}
	if(flag) cout<<"bu yong dao le"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<b[i][j];
		cout<<endl;
	}
		
		
}
