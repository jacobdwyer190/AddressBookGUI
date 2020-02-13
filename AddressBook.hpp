#pragma once

#include <list>
#include <iostream>
#include "Entry.hpp"

class AddressBook
{
private:
	std::list<Entry*> entries;
public:
	AddressBook();
	~AddressBook();

	void AddEntry(std::string name, std::string phoneNumber, std::string address);
	void SearchAddressBook(std::string name);
	void RemoveAddressBook(std::string name);
	void PrintAddressBook();
};

