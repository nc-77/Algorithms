#include<bits/stdc++.h>
using namespace std;
stack<int>s1,s2,s3;
int main() {
	string s;
	cin>>s;
	int flag=1,f1=0,f2=0,f3=0;

	for(int i=0; i<s.size(); i++) {
		int x,y,z;
		if(s[i]=='(') s1.push(i+1);
		if(s[i]=='{') s2.push(i+1);
		if(s[i]=='[') s3.push(i+1);
		if(s[i]==')') {
			if(s1.empty()) {
				flag=0;
				break;
			} else
				x=s1.top();
			if(s2.empty()) y=0;
			else y=s2.top();
			if(s3.empty()) z=0;
			else z=s3.top();
			if(x<y||x<z) {
				flag=0;
				break;
			} else
				s1.pop();
		}
		if(s[i]=='}') {
			if(s2.empty()) {
				flag=0;
				break;
			} else
				x=s2.top();
			if(s1.empty()) y=0;
			else y=s1.top();
			if(s3.empty()) z=0;
			else z=s3.top();
			if(x<y||x<z) {
				flag=0;
				break;
			} else
				s2.pop();
		}
		if(s[i]==']') {
			if(s3.empty()) {
				flag=0;
				break;
			} else
				x=s3.top();
			if(s1.empty()) y=0;
			else y=s1.top();
			if(s2.empty()) z=0;
			else z=s2.top();
			if(x<y||x<z) {
				flag=0;
				break;
			} else
				s3.pop();
		}
	}
	if(!s1.empty()||!s2.empty()||!s3.empty()) flag=0;

	if(flag) puts("Yes");
	else puts("No");
}
