#pragma once
#include <string>
class String {
private:
	std::string str;
public:
	String(std::string s = "");
	void setter();
	std::string getter() const;
	int get_length() const;
	String operator +(const String& source);
	String operator - (const String& source);
	void str_states();
	int operator > (const String& source);
	int operator == (const String& source);
};

