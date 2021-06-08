#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
    vector<int>vec;
    int x;
   while(cin>>x&&x!=-1){
       vec.push_back(x);
   }
   while(cin>>x&&x!=-1){
       vec.push_back(x);
   }
   sort(vec.begin(),vec.end());
   int len=vec.size();
   if(!len){
       cout<<"NULL"<<endl;
       return 0;
   }
   for(int i=0;i<len;i++){
       
       cout<<vec[i];
       if(i!=len-1) cout<<" ";
   }
   return 0;
}
