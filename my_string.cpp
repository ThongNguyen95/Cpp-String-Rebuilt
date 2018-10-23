#include <cstring>
#include "my_string.h"
using std::cin;
using std::cout;

//initializing static class member
int MyString::num_strings = 0;

//static function
int MyString::HowMany() {
	return num_strings;
}

//Constructors

//Default Constructor
MyString::MyString() {
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

//Create string object from c style string
MyString::MyString(const char * s) {
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

//Copy Constructor
MyString::MyString(const MyString & st) {
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	num_strings++;
}

//Destructor
MyString::~MyString() {
	--num_strings;
	delete[] str;
}

//Overloaded member operators
//Assignment operators
MyString & MyString::operator=(const MyString& st) {
	if (this == &st) 
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

MyString & MyString::operator=(const char * s) {
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

//single character access read-write operator
char & MyString::operator[](int i) {
	return str[i];
}
const char & MyString::operator[](int i) const {
	return str[i];
}

//Friend operator methods
bool operator<(const MyString & st1, const MyString & st2) {
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const MyString & st1, const MyString & st2) {
	return (st2 < st1);
}

bool operator==(const MyString & st1, const MyString & st2) {
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const MyString & st) {
	os << st.str;
	return os;
}

istream & operator>>(istream & is, MyString & st) {
	char temp[MyString::CINLIM];
	is.get(temp, MyString::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}