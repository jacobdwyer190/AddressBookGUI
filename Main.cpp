#include <iostream>
#include <TGUI/TGUI.hpp>
#include "AddressBook.hpp"

/*Created by Jacob Dwyer
 *
 *Basic GUI for an addressbook that will allow a user to add, remove, and edit an entry
 *Will also allow a user to save(export using serialization), load, and sort the list
 */

void updateListBox(tgui::Panel::Ptr listBox, AddressBook *uEntry);
void entryHandler(tgui::EditBox::Ptr nameBox, tgui::EditBox::Ptr numBox, tgui::EditBox::Ptr addBox, AddressBook* uEntry, tgui::ListBox::Ptr listBox);
//void editHandler(tgui::EditBox::Ptr nameEditBox);
void removeHandler(tgui::EditBox::Ptr removeBox, AddressBook *uEntry);
//void sortHandler();
//void savetHandler();
//void loadHandler();

void loadWidgets(tgui::Gui& gui, AddressBook *uEntry) {
	//create a label for the title of the window
	//and sets position and size
	tgui::Label::Ptr title = tgui::Label::create("Address Book");
	title->setTextSize(40);
	title->setPosition(375, 0);

	//creates a chatbox for displaying the address book
	tgui::ListBox::Ptr listBox = tgui::ListBox::create();
	listBox->setSize(800, 600);
	listBox->setPosition(100, 100);
	
	//tgui::Scrollbar::Ptr scroll = tgui::Scrollbar::create();

	/*----------Creates panels for each area of user interaction----------*/
			  //widget position is offset by thier panel position//

	tgui::Panel::Ptr entryPanel = tgui::Panel::create();
	entryPanel->setPosition(0, 750);

	tgui::Panel::Ptr editPanel = tgui::Panel::create();
	editPanel->setPosition(400, 750);

	tgui::Panel::Ptr removePanel = tgui::Panel::create();
	removePanel->setPosition(700, 750);

	tgui::Panel::Ptr sortPanel = tgui::Panel::create();
	sortPanel->setPosition(0, 875);

	/*----------Creates labels, edit boxes, and buttons for each panel----------*/
						//sets their size and postion//

	//-----addEntry panel widgets-----
	tgui::Label::Ptr name = tgui::Label::create("Name:");
	name->setPosition(100, 0);

	tgui::Label::Ptr number = tgui::Label::create("Number:");
	number->setPosition(100, 20);

	tgui::Label::Ptr address = tgui::Label::create("Address:");
	address->setPosition(100, 40);

	tgui::EditBox::Ptr nameBox = tgui::EditBox::create();
	nameBox->setSize(100, 20);
	nameBox->setPosition(175, 0);

	tgui::EditBox::Ptr numBox = tgui::EditBox::create();
	numBox->setSize(100, 20);
	numBox->setPosition(175, 20);

	tgui::EditBox::Ptr addBox = tgui::EditBox::create();
	addBox->setSize(100, 20);
	addBox->setPosition(175, 40);

	tgui::Button::Ptr addEntry = tgui::Button::create("Add Entry");
	addEntry->setSize(100, 20);
	addEntry->setPosition(135, 70);

	//add all widgets to the panel
	entryPanel->add(name);
	entryPanel->add(number);
	entryPanel->add(address);
	entryPanel->add(nameBox);
	entryPanel->add(numBox);
	entryPanel->add(addBox);
	entryPanel->add(addEntry);

	//connect the buttons to their handlers
	addEntry->connect("pressed", entryHandler, nameBox, numBox, addBox, uEntry, listBox);

	/*-----editEntry panel widgets-----*/
	tgui::Label::Ptr nameEdit = tgui::Label::create("Name:");
	nameEdit->setPosition(0, 0);

	tgui::EditBox::Ptr nameEditBox = tgui::EditBox::create();
	nameEditBox->setSize(100, 20);
	nameEditBox->setPosition(50, 0);

	tgui::Button::Ptr editEntry = tgui::Button::create("Edit Entry");
	editEntry->setSize(100, 20);
	editEntry->setPosition(35, 70);

	//add all widgets to the panel
	editPanel->add(nameEdit);
	editPanel->add(nameEditBox);
	editPanel->add(editEntry);

	/*-----removeEntry panel widgets-----*/
	tgui::Label::Ptr nameRemove = tgui::Label::create("Name:");
	nameRemove->setPosition(0, 0);

	tgui::EditBox::Ptr removeBox = tgui::EditBox::create();
	removeBox->setSize(100, 20);
	removeBox->setPosition(50, 0);

	tgui::Button::Ptr removeEntry = tgui::Button::create("Remove Entry");
	removeEntry->setSize(100, 20);
	removeEntry->setPosition(35, 70);

	//connect the buttons to their handlers
	removeEntry->connect("pressed", removeHandler, nameBox, uEntry);

	//add all widgets to the panel
	removePanel->add(nameRemove);
	removePanel->add(removeBox);
	removePanel->add(removeEntry);

	/*-----sortList Panel widgets-----*/
	tgui::RadioButton::Ptr lastNameRadio = tgui::RadioButton::create();
	lastNameRadio->setPosition(100, 0);

	tgui::RadioButton::Ptr firstNameRadio = tgui::RadioButton::create();
	firstNameRadio->setPosition(100, 20);

	tgui::Label::Ptr last = tgui::Label::create("Last Name");
	last->setPosition(150, 0);

	tgui::Label::Ptr first = tgui::Label::create("First Name");
	first->setPosition(150, 20);

	tgui::Button::Ptr sort = tgui::Button::create("Sort");
	sort->setSize(100, 20);
	sort->setPosition(135, 70);

	//add all widgets to the panel
	sortPanel->add(lastNameRadio);
	sortPanel->add(firstNameRadio);
	sortPanel->add(last);
	sortPanel->add(first);
	sortPanel->add(sort);

	/*----- Creates remaining widgets for the window -----*/

	tgui::Button::Ptr load = tgui::Button::create("Load");
	load->setSize(100, 20);
	load->setPosition(435, 945);

	tgui::Button::Ptr save = tgui::Button::create("Save");
	save->setSize(100, 20);
	save->setPosition(735, 945);

	//add all panels and widgets to the window
	gui.add(title);
	gui.add(listBox);
	gui.add(entryPanel);
	gui.add(editPanel);
	gui.add(removePanel);
	gui.add(sortPanel);
	gui.add(load);
	gui.add(save);
}

int main() {

	//creates window and sets size
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Address Book");
	tgui::Gui gui(window);
	sf::Event event;
	
	//cretes new addressbook object
	AddressBook *uEntry = new AddressBook();
	
	try
	{
		loadWidgets(gui, uEntry);
	}
	catch (const tgui::Exception & e)
	{
		std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
		return 1;
	}

	//keep the window open until the close button is pressed
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			gui.handleEvent(event);
		}

		//set window color
		window.clear(sf::Color::White);
		//draw the window
		gui.draw();
		//display the window until the close button is pressed
		window.display();
	}
	return EXIT_SUCCESS;
}

void updateListBox(tgui::ListBox::Ptr listBox, AddressBook* uEntry) {
	listBox->addItem(uEntry->PrintAddressBook());
} 

void entryHandler(tgui::EditBox::Ptr nameBox, tgui::EditBox::Ptr numBox, tgui::EditBox::Ptr addBox, AddressBook *uEntry, tgui::ListBox::Ptr listBox){
		uEntry->AddEntry(nameBox->getText(), numBox->getText(), addBox->getText());
		updateListBox(listBox, uEntry);
		nameBox->setText("");
		numBox->setText("");
		addBox->setText("");
		uEntry->PrintAddressBook(); //for testing purposes
}

void removeHandler(tgui::EditBox::Ptr nameBox, AddressBook *uEntry) {
		uEntry->RemoveEntry(nameBox->getText());
		uEntry->PrintAddressBook(); //for testing purposes
}