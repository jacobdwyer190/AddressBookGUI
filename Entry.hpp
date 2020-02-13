#pragma once

#include <string>

class Entry
{

private:
	std::string name;
	std::string phoneNumber;
	std::string address;

public:
	Entry();
	Entry(std::string name, std::string phoneNumber, std::string address);
	std::string GetName();
	std::string GetPhoneNumber();
	std::string GetAddress();
	std::string ToString();
	~Entry();
};

#pragma once
