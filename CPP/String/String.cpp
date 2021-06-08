#include<cstring>
#include<iostream>
#include"String.h"
using namespace std;

int String::num_strings = 0;

String::String() {
    num_strings++;
    len = 0;
    str = nullptr;
    //cout<<num_strings<<":\""<<str<<"\"object created\n";
}

String::String(const char* s) {
    num_strings++;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    //cout<<num_strings<<":\""<<str<<"\"object created\n";
}

String::String(const String& s) {
    num_strings++;
    str = new char[len + 1];
    strcpy(str, s.str);
    len = s.len;
    //cout<<num_strings<<":\""<<str<<"\"object copyed\n";
}

String::~String() {
    --num_strings;
    //cout << "\"" << str << "\"object deleted. ";
    //cout << num_strings << " left\n";
    delete[]str;
}
String& String:: operator=(const String& s) {
    if (this == &s)
        return *this;
    delete[]str;
    str = new char[s.len + 1];
    strcpy(str, s.str);
    len = s.len;
    return *this;
}
istream& operator>>(istream& is, String& st) {
    char temp[100];
    is.get(temp, 100);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    st.len = strlen(st.str);
    //cout<<st.len<<endl;
    return is;
}

ostream& operator<<(ostream& os, const String& st) {
    os << st.str;
    return os;
}

bool operator<(const String& st, const String& st2) {
    if (strcmp(st.str, st2.str) < 0)
        return true;
    else return false;
}

bool operator>(const String& st, const String& st2) {
    if (strcmp(st.str, st2.str) > 0)
        return true;
    else return false;
}

bool operator==(const String& st, const String& st2) {
    if (strcmp(st.str, st2.str) == 0)
        return true;
    else return false;
}

char& String::operator[](const int i) {
    return str[i];
}

const char& String::operator[](const int i)const {
    return str[i];
}

