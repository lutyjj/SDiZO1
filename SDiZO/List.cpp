#include <iostream>
#include <fstream>
#include <random>
#include "List.h"


void List::display() {
	// Set pointer to head of list
	ElemList* tmp = head;
	std::cout << "Size: " << size << " [ ";
	// Cycle through list and show every element
	while (tmp) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << "]";
}

void List::clear() {
	// Check if head exists
	if (head) {
		ElemList* tmp = head, *tmp_next;
		while (tmp) {
			tmp_next = tmp->next;
			delete tmp;
			tmp = tmp_next;
		}
		head = nullptr;
		size = 0;
	}
}

bool List::search(int value) {
	if (head) {
		ElemList* tmp = head;
		while (tmp) {
			if (tmp->data == value) return true;
			tmp = tmp->next;
		}
	}
	return false;
}

void List::push_at(int value, int index) {
	if (index > size - 1) push_back(value);
	else if (index == 0 || head == nullptr) push_front(value);
	else {
		ElemList* tmp = head;
		while (index > 1 && tmp->next) {
			tmp = tmp->next;
			index--;
		}
		ElemList* p = new ElemList;
		p->data = value;
		p->next = tmp->next;
		p->prev = tmp;
		tmp->next = p;
		size++;
	}
}

void List::pop_at(int index) {
	if (head) {
		if (index >= size - 1) pop_back();
		else if (index == 0) pop_front();
		else {
			ElemList* tmp = head;
			while (index > 0 && tmp->next) {
				tmp = tmp->next;
				index--;
			}
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			delete tmp;
			size--;
		}
	}
}

void List::fill_random(int size) {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 100);

	clear();
	int counter = 0;
	while (counter < size) {
		push_back(dist(rng));
		counter++;
	}
}

void List::readFromFile(std::string fileName) {
	clear();
	std::ifstream file;
	int value;
	file.open(fileName);
	if (file) {
		file >> value;
		std::cout << "Number of items: " << value;
		while (file >> value) {
			push_back(value);
		}
	}
	else std::cerr << "Error while reading file";
	file.close();
}

void List::push_front(int value) {
	ElemList* p = new ElemList;
	p->data = value;
	p->next = head;
	if (head) head->prev = p;
	head = p;
	size++;
}

void List::pop_front() {
	if (head) {
		ElemList* p = head;
		head = head->next;
		delete p;
		size--;
	}
}

void List::pop_back() {
	ElemList* p = head;
	if (head) {
		if (head->next) {
			while (p->next->next)
				p = p->next;
			delete p->next;
			p->next = nullptr;
			size--;
		}
		else {
			delete p;
			head = nullptr;
			size = 0;
		}
	}
}

void List::push_back(int value) {
	ElemList* v = new ElemList;
	ElemList* e = head;
	v->data = value;
	v->next = nullptr;
	if (head) {
		while (e->next)
			e = e->next;
		e->next = v;
		v->prev = e;
	}
	else head = v;
	size++;
}