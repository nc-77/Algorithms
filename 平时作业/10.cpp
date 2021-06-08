#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
   string s;
   getline(cin,s);
   int blank=0;
   int dig=0;
   int res=0;
   for(int i=0;i<s.size();i++){
       if(s[i]==' ') blank++;
       else if(s[i]>='0'&&s[i]<='9') dig++;
       else res++;
   }
   
   printf("blank = %d, digit = %d, other = %d",blank,dig,res);
   return 0;
}
