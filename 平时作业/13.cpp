#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int vis[10];
int index[10];
int main()
{
   string s;
   getline(cin,s);
   for(int i=0;i<11;i++){
       vis[s[i]-'0']++;
   }
   cout<<"int[] arr = new int[]{";
   int first=0;
   int pos=0;
   for(int i=9;i>=0;i--){
       if(vis[i]){
           if(!first) cout<<i;
           else cout<<','<<i;
           first=1;
           index[i]=pos++;
       }
   }
   first=0;
   cout<<"};"<<endl;
   cout<<"int[] index = new int[]{";
   for(int i=0;i<11;i++){

           if(!first) cout<<index[s[i]-'0'];
           else cout<<","<<index[s[i]-'0'];
           first=1;
           
       
   }
   cout<<"};"<<endl;
   return 0;
}
