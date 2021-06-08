#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
   string s;
   getline(cin,s);
   map<char,int>lev;
   stack<char>op;
   vector<char>ans;
   lev['/']=lev['*']=1;
   lev['(']=lev[')']=2;
   int flag=0;
   for(int i=0;i<s.size();i++){
       //debug(s[i]);
       if((i<1||s[i-1]=='(')&&(s[i]=='+'||s[i]=='-')||s[i]=='.'||s[i]>='0'&&s[i]<='9'){
           if(flag)
			{
				cout<<" ";
			}
            flag++;
           if(s[i]!='+') cout<<s[i];
           while(s[i+1]=='.'||s[i+1]>='0'&&s[i+1]<='9')
			{
				i++;
				cout<<s[i];
			}
       }
       else{
           if(op.empty()) op.push(s[i]);
           else {
               char top=op.top();
               if(s[i]==')'){
                   while(top!='('){
                       cout<<" "<<top;
                       op.pop();
                       top=op.top();
                   }
                   op.pop();
               }
               else if(lev[s[i]]>lev[top])
                    op.push(s[i]);
               else {
                   while(top!='('&&lev[s[i]]<=lev[top])
                   {
                       cout<<" "<<top;
                       op.pop();
                       if(op.empty()) break; 
                       top=op.top();
                   }
                   op.push(s[i]);
               }
               
           }
       }
   }
    while(!op.empty()){
        char top=op.top();
        ans.push_back(top);
        op.pop();
    }
    for(int i=0;i<ans.size();i++){
         cout<<" "<<ans[i];
    }

   
   return 0;
}
