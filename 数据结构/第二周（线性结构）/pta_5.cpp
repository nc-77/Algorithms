#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
   int maxsize,n,k;
   cin>>maxsize>>n>>k;
   while(k--)
   {
       queue<int>que;
       stack<int>sta;
       for(int i=1;i<=n;i++)
       {
           int x;
           cin>>x;
           que.push(x);
       }
       int flag=1;
       for(int i=1;i<=n;i++)
       {
           sta.push(i);
           if(sta.size()>maxsize) {
               flag=0;
               break;
           }
           while(!sta.empty()&&sta.top()==que.front())
           {
               sta.pop();
               que.pop();
           }
       } 
       if(!flag) cout<<"NO"<<endl;
       else {
           if(que.empty()) cout<<"YES"<<endl;
           else cout<<"NO"<<endl;
       }
   }
   //system("pause");
   return 0;
}
