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

void AddressBook::RemoveAddressBook(std::string name)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) {
		if ((*currentEntry)->GetName().compare(name) == 0) {
			this->entries.remove(*currentEntry);
		}
	}
}

void AddressBook::PrintAddressBook()
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) {
		std::cout << (*currentEntry)->ToString() << std::endl << "\n";
		std::string str;
		str = (*currentEntry)->ToString();
		//return str;
	}
}