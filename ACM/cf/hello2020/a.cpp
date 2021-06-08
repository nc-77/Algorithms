#include<bits/stdc++.h>
using namespace std;
char s[100][100],t[100][100];
int main()
{
	int n,m,q,y,y1,y2;
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	for(int i=1;i<=m;i++)
	cin>>t[i];
	cin>>q;
	while(q--)
	{
		cin>>y;
		y1=(y+n-1)%n+1;
		y2=(y+m-1)%m+1;
		printf("%s%s\n",s[y1],t[y2]);
	}
return 0;
 } 
