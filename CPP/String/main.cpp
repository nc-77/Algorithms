#include<iostream>
#include<algorithm>
#include"String.h"
using namespace std;
const int Num = 5;
int main()
{
	String name;
	cout << "Hi,what is your name?" << endl;
	cin >> name;
	cout << name << ",please enter up to " << Num << " short words:" << endl;
	String words[Num];
	String minlen = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	for (int i = 0; i < Num; i++)
	{
		cout << i + 1 << ":";
		cin >> words[i];
		if (words[i].length() < minlen.length())
			minlen = words[i];
	}
	cout << "Here are your words:" << endl;
	for (int i = 0; i < Num; i++)
		cout << i + 1 << ":" << words[i] << endl;
	sort(words, words + Num);
	cout << "Here is minlen word:" << minlen << endl;
	cout << "Here are sorted words:" << endl;
	for (int i = 0; i < Num; i++)
		cout << i + 1 << ":" << words[i] << endl;
	cout << "Here is the number of words:" << endl;
	cout << String::Howmany() << endl;
	return 0;
}