#include <iostream>
#include <conio.h>
#include <string>
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
		std::cout << std::endl;

		switch (option) {
		case '1':
			menu_list();
			break;
		}

	} while (option != '0');

	return 0;
}

void menu_list()
{
	char opt;
	std::string fileName;
	int value;
	List list;

	do {
		listMenu();
		opt = _getche();
		switch (opt) {
		case '1':
			list.pop_front();
			list.display();
			break;

		case '2':
			list.pop_back();
			list.display();
			break;

		case '3':
			std::cout << "Enter value: ";
			std::cin >> value;
			list.push_front(value);
			list.display();
			break;

		case '4':
			std::cout << "Enter value: ";
			std::cin >> value;
			list.push_back(value);
			list.display();
			break;
		}
	} while (opt != '0');
}

void listMenu() {
	std::cout << std::endl;
	std::cout << "List" << std::endl;
	std::cout << "1. Pop front" << std::endl;
	std::cout << "2. Pop back" << std::endl;
	std::cout << "3. Push front" << std::endl;
	std::cout << "4. Push back" << std::endl;
	std::cout << "0. Powrot do menu" << std::endl;
	std::cout << "Podaj opcje:";
}