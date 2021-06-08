#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
char x[maxn],s1[maxn],s2[maxn];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       
       int n;
       cin>>n;
       getchar();
       scanf("%s",x);
       int flag=0;
        for(int i=0;i<n;i++)
        {  
            if((x[i]=='2')&&!flag)
            {
               
                s1[i]='1';
                s2[i]='1';
                //debug(s1);
            }
            else if(x[i]=='0'&&!flag)
            {
                s1[i]='0';
                s2[i]='0';
            }
            if((x[i]=='2')&&flag)
            {
               
                s1[i]='0';
                s2[i]='2';
                //debug(s1);
            }
            else if(x[i]=='0'&&flag)
            {
                s1[i]='0';
                s2[i]='0';
            }
            else if(x[i]=='1'&&!flag)
            {
                flag=1;
                s1[i]='1',s2[i]='0';
            }
            else if(x[i]=='1'&&flag)
            {
                s1[i]='0',s2[i]='1';
            }
        }
        for(int i=0;i<n;i++) cout<<s1[i];
        cout<<endl;
         for(int i=0;i<n;i++) cout<<s2[i];
        cout<<endl;
   }
   //system("pause");
   return 0;
}
