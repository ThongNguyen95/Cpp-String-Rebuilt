#ifndef MY_STRING_H_
#define MY_STRING_H_
#include <iostream>
using std::ostream;
using std::istream;

class MyString {
private:
	char * str; //pointer to string
	int len; //length of string
	static int num_strings; //number of strings
	static const int CINLIM = 80;
public:
	//Constructors and some member methods
	MyString(); //default constructor
	MyString(const char * s);
	MyString(const MyString &);
	~MyString();
	int length() const { return len; }
	//Overloaded operator member methods
	MyString & operator=(const MyString	&);
	MyString & operator=(const char *);
	char & operator[](int i);
	const char & operator[](int i) const;
	//friend functions
	friend bool operator<(const MyString & st1, const MyString & str2);
	friend bool operator>(const MyString & st1, const MyString & str2);
	friend bool operator==(const MyString & st1, const MyString & str2);
	friend ostream & operator<<(ostream & os, const MyString & st);
	friend istream & operator>>(istream & is, MyString & st);
	//static member method
	static int HowMany();

};

#endif // !MY_STRING_H_
