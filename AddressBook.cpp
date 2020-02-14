#include "AddressBook.hpp"


AddressBook::AddressBook()
{
}


AddressBook::~AddressBook()
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) {
		delete((*currentEntry));
	}
}

void AddressBook::AddEntry(std::string name, std::string phoneNumber, std::string address)
{
	this->entries.push_back(new Entry(name, phoneNumber, address));
}

void AddressBook::SearchAddressBook(std::string name)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) {
		if ((*currentEntry)->GetName().compare(name) == 0) {
			std::cout << (*currentEntry)->ToString() << std::endl;
		}
	}
}

void AddressBook::RemoveEntry(std::string name)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) {
		if ((*currentEntry)->GetName().compare(name) == 0) {
			this->entries.remove(*currentEntry);
		}
	}
}

std::string AddressBook::PrintAddressBook()
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) {
		std::cout << (*currentEntry)->ToString() << std::endl;//testing purposes
		std::string str = (*currentEntry)->ToString();
		return str;
	}
}
