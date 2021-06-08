#include<iostream>
#include<map>
#include<string>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int power[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[]={'1','0','X','9','8','7','6','5','4','3','2'};

map<int,char>check;
bool work(string &s){
    int sum=0;
    for(int i=0;i<17;i++){
        int num=s[i]-'0';
        //debug(num);
        sum+=num*power[i];
    }
    
    
    return (char(s[17])==check[sum%11]);
}
int main()
{
   int n;
   cin>>n;
   getchar();
   string s;
   for(int i=0;i<11;i++){
       check[i]=M[i];
       
   }
   int flag=0;
   for(int i=0;i<n;i++){
       getline(cin,s);
       if(!work(s)){
           cout<<s<<endl;
           flag=1;
       }
   }
   if(!flag)puts("All passed");
   return 0;
}
