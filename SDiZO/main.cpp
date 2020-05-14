#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "List.h"
#include "Array.h"
#include "BinaryHeap.h"
#include "RedBlackTree.h"
#include "Timer.h"
#include "TestList.h"
#include "TestArray.h"
#include "TestBinaryHeap.h"
#include "TestRBTree.h"
#include "main.h"
#include <windows.h>

void menu_list();
void menu_list_entries();
void menu_array();
void menu_array_entries();
void menu_binary_heap();
void menu_binary_heap_entries();
void menu_red_black_tree();
void menu_red_black_tree_entries();

int main() {
	char option;
	do {
		std::cout << "==== MENU ====" << std::endl;
		std::cout << "1. List" << std::endl;
		std::cout << "2. Array" << std::endl;
		std::cout << "3. Binary heap" << std::endl;
		std::cout << "4. Red-Black tree" << std::endl;
		std::cout << "Enter: ";
		option = _getche();
		std::system("CLS");
		switch (option) {
		case '1':
			menu_list();
			break;
		case '2':
			menu_array();
			break;
		case '3':
			menu_binary_heap();
			break;
		case '4':
			menu_red_black_tree();
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
		menu_list_entries();
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
			timer.showTimeElapsed();
			break;

		case 3:
			timer.start();
			list.pop_back();
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 4:
			std::cout << "Enter index: ";
			std::cin >> index;
			timer.start();
			list.pop_at(index);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 5:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			list.push_front(value);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 6:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			list.push_back(value);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 7:
			std::cout << "Enter value: ";
			std::cin >> value;
			std::cout << "Enter index: ";
			std::cin >> index;
			timer.start();
			list.push_at(value, index);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 8:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			list.search(value) ? std::cout << "Value found \n" : std::cout << "Value not found \n";
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 9:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			list.readFromFile(fileName);
			break;

		case 10:
			list.display();
			break;

		case 11:
			std::cout << "Test started. \n";
			TestList test(500, 100, 100);
			test.startTest();
			test.setPreferences(1000, 100, 100);
			test.startTest();
			test.setPreferences(2000, 100, 100);
			test.startTest();
			test.setPreferences(4000, 100, 200);
			test.startTest();
			test.setPreferences(6000, 100, 300);
			test.startTest();
			test.setPreferences(8000, 50, 400);
			test.startTest();
			test.setPreferences(10000, 50, 500);
			test.startTest();
			test.setPreferences(16000, 50, 800);
			test.startTest();
			std::cout << "Test finished. \n";
			break;
		}
		std::cout << std::endl;
	} while (opt != 0);
}

void menu_list_entries() {
	std::cout << "1. Fill with random numbers" << std::endl;
	std::cout << "2. Pop front" << std::endl;
	std::cout << "3. Pop back" << std::endl;
	std::cout << "4. Pop at index" << std::endl;
	std::cout << "5. Push front" << std::endl;
	std::cout << "6. Push back" << std::endl;
	std::cout << "7. Push at index" << std::endl;
	std::cout << "8. Search for value" << std::endl;
	std::cout << "9. Build from file" << std::endl;
	std::cout << "10. Show structure" << std::endl;
	std::cout << "11. Run test" << std::endl;
	std::cout << "0. Powrot do menu" << std::endl;
	std::cout << "Enter: ";
}

void menu_array() {
	int opt;
	std::string fileName;
	int value, index;
	std::ifstream inFile;
	Array array;
	Timer timer;

	do {
		std::cout << std::endl << "ARRAY" << std::endl;
		array.display();
		std::cout << std::endl;
		menu_array_entries();
		std::cin >> opt;
		std::cout << std::endl;
		switch (opt) {
		case 1:
			std::cout << "Enter list size: ";
			std::cin >> value;
			array.fill_random(value);
			break;

		case 2:
			timer.start();
			array.pop_front();
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 3:
			timer.start();
			array.pop_back();
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 4:
			std::cout << "Enter index: ";
			std::cin >> index;
			timer.start();
			array.pop_at(index);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 5:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			array.push_front(value);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 6:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			array.push_back(value);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 7:
			std::cout << "Enter value: ";
			std::cin >> value;
			std::cout << "Enter index: ";
			std::cin >> index;
			timer.start();
			array.push_at(value, index);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 8:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			array.search(value) ? std::cout << "Value found \n" : std::cout << "Value not found \n";
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 9:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			array.readFromFile(fileName);
			break;

		case 10:
			array.display();
			break;

		case 11:
			std::cout << "Test started. \n";
			TestArray test(500, 100, 100);
			test.startTest();
			test.setPreferences(1000, 100, 100);
			test.startTest();
			test.setPreferences(2000, 100, 100);
			test.startTest();
			test.setPreferences(4000, 100, 200);
			test.startTest();
			test.setPreferences(6000, 100, 300);
			test.startTest();
			test.setPreferences(8000, 50, 400);
			test.startTest();
			test.setPreferences(10000, 50, 500);
			test.startTest();
			test.setPreferences(16000, 50, 800);
			test.startTest();
			std::cout << "Test finished. \n";
			break;
		}
		std::cout << std::endl;
	} while (opt != 0);
}

void menu_array_entries() {
	std::cout << "1. Fill with random numbers" << std::endl;
	std::cout << "2. Pop front" << std::endl;
	std::cout << "3. Pop back" << std::endl;
	std::cout << "4. Pop at index" << std::endl;
	std::cout << "5. Push front" << std::endl;
	std::cout << "6. Push back" << std::endl;
	std::cout << "7. Push at index" << std::endl;
	std::cout << "8. Search for value" << std::endl;
	std::cout << "9. Build from file" << std::endl;
	std::cout << "10. Show structure" << std::endl;
	std::cout << "11. Run test" << std::endl;
	std::cout << "0. Return to main menu" << std::endl;
	std::cout << "Enter: ";
}

void menu_binary_heap() {
	int opt;
	std::string fileName;
	int value, index;
	std::ifstream inFile;
	BinaryHeap binaryHeap;
	Timer timer;

	do {
		std::cout << std::endl << "BINARY HEAP" << std::endl;
		binaryHeap.display();
		std::cout << std::endl;
		menu_binary_heap_entries();
		std::cin >> opt;
		std::cout << std::endl;
		switch (opt) {

		case 1:
			std::cout << "Enter list size: ";
			std::cin >> value;
			binaryHeap.fillRandom(value);
			break;

		case 2:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			binaryHeap.push(value);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 3:
			timer.start();
			binaryHeap.pop();
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 4:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			binaryHeap.pop_value(value);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 5:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			binaryHeap.search(value) ? std::cout << "Value found \n" : std::cout << "Value not found \n";
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 6:
			timer.start();
			binaryHeap.build();
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 7:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			binaryHeap.readFromFile(fileName);
			break;

		case 10:
			binaryHeap.display();
			break;

		case 11:
			std::cout << "Test started. \n";
			TestRBTree test(500, 100, 100);
			test.startTest();
			test.setPreferences(1000, 100, 100);
			test.startTest();
			test.setPreferences(2000, 100, 100);
			test.startTest();
			test.setPreferences(4000, 100, 200);
			test.startTest();
			test.setPreferences(6000, 100, 300);
			test.startTest();
			test.setPreferences(8000, 50, 400);
			test.startTest();
			test.setPreferences(10000, 50, 500);
			test.startTest();
			test.setPreferences(16000, 50, 800);
			test.startTest();
			std::cout << "Test finished. \n";
			break;
		}
		std::cout << std::endl;
	} while (opt != 0);
}

void menu_binary_heap_entries() {
	std::cout << "1. Fill random" << std::endl;
	std::cout << "2. Push" << std::endl;
	std::cout << "3. Pop" << std::endl;
	std::cout << "4. Pop value" << std::endl;
	std::cout << "5. Search" << std::endl;
	std::cout << "6. Build (repair) heap" << std::endl;
	std::cout << "7. Build from file" << std::endl;
	std::cout << "10. Show structure" << std::endl;
	std::cout << "11. Run test" << std::endl;
	std::cout << "0. Return to main menu" << std::endl;
	std::cout << "Enter: ";
}

void menu_red_black_tree() {
	int opt;
	std::string fileName;
	int value, index;
	std::ifstream inFile;
	RedBlackTree redBlackTree;
	Timer timer;

	do {
		std::cout << std::endl << "RBTREE" << std::endl;
		redBlackTree.display();
		std::cout << std::endl;
		menu_red_black_tree_entries();
		std::cin >> opt;
		std::cout << std::endl;
		switch (opt) {
		case 1:
			std::cout << "Enter list size: ";
			std::cin >> value;
			redBlackTree.fillRandom(value);
			break;

		case 2:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			redBlackTree.insert(value);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 3:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			//redBlackTree.remove(value);
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 4:
			std::cout << "Enter value: ";
			std::cin >> value;
			timer.start();
			redBlackTree.find(value) ? std::cout << "Value found \n" : std::cout << "Value not found \n";
			timer.stop();
			timer.showTimeElapsed();
			break;

		case 5:
			std::cout << "Enter file name: ";
			std::cin >> fileName;
			redBlackTree.readFromFile(fileName);
			break;

		case 10:
			std::cout << "Test started. \n";
			TestRBTree test(500, 100, 100);
			test.startTest();
			test.setPreferences(1000, 100, 100);
			test.startTest();
			test.setPreferences(2000, 100, 100);
			test.startTest();
			test.setPreferences(4000, 100, 200);
			test.startTest();
			test.setPreferences(6000, 100, 300);
			test.startTest();
			test.setPreferences(8000, 50, 400);
			test.startTest();
			test.setPreferences(10000, 50, 500);
			test.startTest();
			test.setPreferences(16000, 50, 800);
			test.startTest();
			std::cout << "Test finished. \n";
			break;
		}
		std::cout << std::endl;
	} while (opt != 0);
}

void menu_red_black_tree_entries() {
	std::cout << "1. Fill random" << std::endl;
	std::cout << "2. Insert" << std::endl;
	//std::cout << "3. Remove" << std::endl;
	std::cout << "4. Search" << std::endl;
	std::cout << "5. Build from file" << std::endl;
	std::cout << "10. Run test" << std::endl;
	std::cout << "0. Return to main menu" << std::endl;
	std::cout << "Enter: ";
}