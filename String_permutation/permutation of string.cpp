//============================================================================
// Name        : permutation.cpp
// Author      : anirudh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

string remove_spaces(string str);
bool check_permutation(string a, string b);
bool cp(string a, string b);

int main() {
	string a, b;
	cout << "Enter the first string: ";
	getline(cin, a);
	cout << "Enter the second string: ";
	getline(cin, b);

	a = remove_spaces(a);
	b = remove_spaces(b);

	if(cp(a,b))
	{
		cout << "\nYes!" << endl;
	}
	else
	{
		cout << "\nNo!" << endl;
	}


//	if(check_permutation(a, b))
//	{
//		cout << "\nYes!" << endl;
//	}
//	else
//	{
//		cout << "\nNo!" << endl;
//	}

	return 0;
}



string remove_spaces(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == ' ')
		{
			str.erase(i,1);
		}
	}
	return str;
}

bool check_permutation(string a, string b)  //without using break statement
{
	if(a.length() != b.length())
		return false;

	int len = a.length();
	int x = 0;
	int t;
	for(int i = 0; i < len; i++)
	{
		t = x;
		for( int j = 0; j < b.length() && x == t ; j++)
		{
			if(a[i] == b[j])
			{
				x++;
				b.erase(b.begin()+j);
			}
		}
	}
	cout << b.length() << endl;
	if(x == len && b.length() == 0)
		return true;
	else
		return false;
}

bool cp(string a, string b)  //using break statement and return statement
{
	if(a.length() != b.length())
		return false;

	for(int i = 0; i < a.length(); i++)
	{
		for(int j = 0; j < b.length(); j++)
		{
			if(a[i] == b[j])
			{
				b.erase(b.begin()+j);
				break;
			}
		}
	}

	return (b.length() == 0);

}
