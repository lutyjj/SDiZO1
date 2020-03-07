#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "List.h"
#include "main.h"

void menu_list();
void listMenu();

int main() {
	char option;
	do {
		std::cout << "==== MENU ====" << std::endl;
		std::cout << "1. List" << std::endl;
		std::cout << "Enter: ";
		option = _getche();
		std::system("CLS");
		switch (option) {
		case '1':
			menu_list();
			break;
		}

	} while (option != '0');

	return 0;
}

void menu_list() {
	char opt;
	std::string fileName;
	int value;
	std::ifstream inFile;
	List list;

	do {
		std::cout << std::endl << "LIST" << std::endl;
		list.display();
		std::cout << std::endl;
		listMenu();
		opt = _getche();
		std::cout << std::endl;
		switch (opt) {
		case '1':
			list.pop_front();
			break;

		case '2':
			list.pop_back();
			break;

		case '3':
			std::cout << "Enter value: ";
			std::cin >> value;
			list.push_front(value);
			break;

		case '4':
			std::cout << "Enter value: ";
			std::cin >> value;
			list.push_back(value);
			break;

		case '5':
			std::cout << "Enter value: ";
			std::cin >> value;
			list.search(value) ? std::cout << "Value found" : std::cout << "Value not found";
			break;

		case '6':
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			list.readFromFile(fileName);
			break;

		case '7':
			std::cout << "Enter value: ";
			std::cin >> value;
			int index;
			std::cout << "Enter index: ";
			std::cin >> index;
			list.push_random(value, index);
		}
		std::cout << std::endl;
	} while (opt != '0');
}

void listMenu() {
	std::cout << "1. Pop front" << std::endl;
	std::cout << "2. Pop back" << std::endl;
	std::cout << "3. Push front" << std::endl;
	std::cout << "4. Push back" << std::endl;
	std::cout << "5. Search for value" << std::endl;
	std::cout << "6. Build from file" << std::endl;
	std::cout << "0. Powrot do menu" << std::endl;
	std::cout << "Podaj opcje: ";
}