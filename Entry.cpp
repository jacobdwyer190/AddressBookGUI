#include "Entry.hpp"

Entry::Entry()
{
	this->name = "";
	this->phoneNumber = "";
	this->address = "";
}

Entry::Entry(std::string name, std::string phoneNumber, std::string address)
{
	this->name = name;
	this->phoneNumber = phoneNumber;
	this->address = address;
}

std::string Entry::GetName()
{
	return this->name;
}

std::string Entry::GetPhoneNumber()
{
	return this->phoneNumber;
}

std::string Entry::GetAddress()
{
	return this->address;
}

std::string Entry::ToString()
{
	return std::string(this->name + " " + this->phoneNumber + " " + this->address);
}

Entry::~Entry()
{
}
