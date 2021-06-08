#include<iostream>
#include<cstring>
#include<stack>
#define debug(x) cout<<#x<<'='<<x<<endl
#define LEFT 0
#define RIGHT 1
using namespace std;
struct node
{
	int left,right;
}a[150];
void postorder(int root)
{
	static int first=1;
	if(root!=-1)
	{
		postorder(a[root].left);
		postorder(a[root].right);
		if(first){cout<<root;
		first=0;}
		else cout<<" "<<root;
	}
}
int main()
{
   int n;
   cin>>n;
   memset(a,-1,sizeof(a));
   string op;
	int x;cin>>op>>x;
   int fa=x,root=x,child=LEFT;
   stack<int>s;
   s.push(x);
   for(int i=0;i<n+n-1;i++)
   {
       cin>>op;
       if(op=="Push"){
           cin>>x;
		   if(child==LEFT)
		   a[fa].left=x;
		   else 
		   a[fa].right=x;
		   fa=x;
		   child=LEFT;
		   s.push(x);
       }
	   else {
		   fa=s.top();
		   s.pop();
		   child=RIGHT;
	   }
   }
   postorder(root);
   return 0;
}
