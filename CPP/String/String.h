#include<iostream>
using namespace std;
#ifndef STRNGBAD_H
#define STRNGBAD_H
class String
{
private:
    char* str;
    int len;
    static int num_strings;
public:
    
    String();//无参数 默认构造
    String(const char* s);//带参数 构造
    String(const String& s);//复制构造
    ~String();
    int length()const { return len; };
    String& operator=(const String& s);
    friend istream& operator>>(istream& is, String& st);
    friend ostream& operator<<(ostream& os, const String& st);
    friend bool operator<(const String& st, const String& st2);
    friend bool operator>(const String& st, const String& st2);
    friend bool operator==(const String& st, const String& st2);
    char& operator[](const int i);
    const char& operator[](const int i)const;
    static int Howmany() { return num_strings; };
};
#endif // !STRNGBAD_H

