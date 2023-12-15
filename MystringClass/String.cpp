#include "String.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
String::String(string s)
	: str(s) {
}
void String::setter() {
	std::cout << "Enter a String: ";
	getline(cin, str);
}
string String::getter() const {
	return str;
}
int String::get_length() const {
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		count += 1;
	}
	return count;
}
String String::operator +(const String& source) {
	String temp;
	temp.str = str + " " + source.str;
	return temp;
}
String String::operator -(const String& source) {
	int c{};
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == source.str[0]) {
			int c = 0;
			for (int j = 0; j < source.str.size(); j++) {
				if (str[i + j] == source.str[j])
					c += 1;
			}
			if (c == source.str.size()) {
				std::cout << "Substring found.\n";
				str.erase(i, c);
				return *this;
			}
		}
	}
	std::cout << "Substring not found\n";
	return *this;
}
void String::str_states() {
	int spaces{}, capital{}, small{}, special_char{}, digits{};
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ')
			spaces++;
		else if (int(str[i]) >= 48 && int(str[i]) <= 57)
			digits++;
		else if (int(str[i]) >= 65 && int(str[i]) <= 90)
			capital++;
		else if (int(str[i]) >= 97 && int(str[i]) <= 122)
			small++;
		else
			special_char++;
	}
	cout << "Here are the States of String: " << str << endl;
	cout << capital << " : capital Letters\n";
	cout << small << " : Small Letters\n";
	cout << digits << " : Digits\n";
	cout << spaces << " : Spaces\n";
	cout << special_char << " : Special Characters\n";
}
int String::operator > (const String& source) {
	int s_str{}, s_source{};
	for (int i = 0; i < str.size(); i++) {
		s_str += int(str[i]);
	}
	for (int i = 0; i < source.str.size(); i++) {
		s_source += int(source.str[i]);
	}
	if (s_str > s_source)
		return 1;
	else
		return 0;
}
int String::operator==(const String& source) {
	int s_str{}, s_source{};
	for (int i = 0; i < str.size(); i++) {
		s_str += int(str[i]);
	}
	for (int i = 0; i < source.str.size(); i++) {
		s_source += int(source.str[i]);
	}
	if (s_str == s_source)
		return 1;
	else
		return 0;
}