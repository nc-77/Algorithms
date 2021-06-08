#include<bits/stdc++.h>
#define ll long long
using namespace std;
int pos[200000+10],vis[200000+10],a[200000+10];
int main()
{	
	int n;
 	cin>>n;
 	int size=0;
 	memset(a,-1,sizeof(a));
	for(int i=1;i<=n;i++)
	{	int x;
		cin>>x;
		if(x!=-1) 
		{
			size++;
			vis[x]=1;
		}
		pos[x]=i;
		a[i]=x;
	}
	cout<<"The size of the tree is "<<size<<endl;
	printf("Node %d is the root node of the tree\n",a[1]);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) continue;
		printf("The father of node %d is %d, the left child is %d, and the right child is %d\n",i,a[pos[i]/2],a[pos[i]*2],a[pos[i]*2+1]);
	}  
}
