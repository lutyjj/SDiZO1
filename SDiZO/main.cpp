#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "List.h"
#include "Timer.h"
#include "TestList.h"
#include "main.h"
#include <windows.h>

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
	int opt;
	std::string fileName;
	int value, index;
	std::ifstream inFile;
	List list;
	Timer timer;

	do {
		std::cout << std::endl << "LIST" << std::endl;
		list.display();
		std::cout << std::endl;
		listMenu();
		std::cin >> opt;
		std::cout << std::endl;
		switch (opt) {
		case 1:
			std::cout << "Enter list size: ";
			std::cin >> value;
			list.fill_random(value);
			break;

		case 2:
			timer.start();
			list.pop_front();
			timer.stop();
			break;

		case 3:
			list.pop_back();
			break;

		case 4:
			std::cout << "Enter index: ";
			std::cin >> index;
			timer.start();
			list.pop_at(index);
			timer.stop();
			break;

		case 5:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			list.push_front(value);
			timer.stop();
			break;

		case 6:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			list.push_back(value);
			timer.stop();
			break;

		case 7:
			std::cout << "Enter value: ";
			std::cin >> value;
			std::cout << "Enter index: ";
			std::cin >> index;
			timer.start();
			list.push_at(value, index);
			timer.stop();
			break;

		case 8:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			list.search(value) ? std::cout << "Value found \n" : std::cout << "Value not found \n";
			timer.stop();
			break;

		case 9:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			list.readFromFile(fileName);
			break;

		case 10:
			std::cout << "Test started. \n";
			TestList test(500, 10, 100);
			test.startTest();
			test.setPreferences(1000, 10, 100);
			test.startTest();
			test.setPreferences(2000, 10, 100);
			test.startTest();
			test.setPreferences(4000, 10, 100);
			test.startTest();
			test.setPreferences(6000, 10, 100);
			test.startTest();
			test.setPreferences(8000, 5, 200);
			test.startTest();
			test.setPreferences(10000, 5, 200);
			test.startTest();
			std::cout << "Test finished. \n";
			break;
		}
		std::cout << std::endl;
	} while (opt != '0');
}

void listMenu() {
	std::cout << "1. Fill with random numbers" << std::endl;
	std::cout << "2. Pop front" << std::endl;
	std::cout << "3. Pop back" << std::endl;
	std::cout << "4. Pop random" << std::endl;
	std::cout << "5. Push front" << std::endl;
	std::cout << "6. Push back" << std::endl;
	std::cout << "7. Push random" << std::endl;
	std::cout << "8. Search for value" << std::endl;
	std::cout << "9. Build from file" << std::endl;
	std::cout << "10. Run test" << std::endl;
	std::cout << "0. Powrot do menu" << std::endl;
	std::cout << "Enter: ";
}