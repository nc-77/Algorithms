#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int x,y;
}pos[501];
bool check(node s1,node s2,node s3)
{
	double x1=sqrt((s1.x-s2.x)*(s1.x-s2.x)+(s1.y-s2.y)*(s1.y-s2.y));
	double x2=sqrt((s1.x-s3.x)*(s1.x-s3.x)+(s1.y-s3.y)*(s1.y-s3.y));
	double x3=sqrt((s2.x-s3.x)*(s2.x-s3.x)+(s2.y-s3.y)*(s2.y-s3.y));
	if(x1>=x2+x3||x2>=x1+x3||x3>=x1+x2)
	return false;
	else return true;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>pos[i].x>>pos[i].y;
		
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
			{	
				
				if(!check(pos[i],pos[j],pos[k]))  continue;
				int x1=(pos[i].x-pos[j].x)*(pos[i].x-pos[j].x)+(pos[i].y-pos[j].y)*(pos[i].y-pos[j].y);
				int x2=(pos[i].x-pos[k].x)*(pos[i].x-pos[k].x)+(pos[i].y-pos[k].y)*(pos[i].y-pos[k].y);
				int x3=(pos[k].x-pos[j].x)*(pos[k].x-pos[j].x)+(pos[k].y-pos[j].y)*(pos[k].y-pos[j].y);
				if(x1>x2+x3||x2>x1+x3||x3>x1+x2)
				sum++;
			
			}
			
	cout<<sum<<endl;		
}
