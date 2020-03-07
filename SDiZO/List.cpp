#include <iostream>
#include <fstream>
#include "List.h"

void List::display() {
	ElemList* tmp = head;
	std::cout << "Size: " << size << " [ ";
	while (tmp) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << "]";
}

void List::clear() {
	if (head) {
		ElemList* tmp = head, *tmp_next;
		while (tmp) {
			tmp_next = tmp->next;
			free(tmp);
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

void List::push_random(int value, int index) {
	ElemList* tmp = head;
	ElemList* p = new ElemList;
	p->data = value;

	if (index > size) push_back(value);
	else if (index == 0) push_front(value);
	else {
		while (index - 1 && tmp->next) {
			tmp = tmp->next;
			index--;
		}
		p->next = tmp->next;
		p->prev = tmp;
		tmp->next = p;
	}
}

void List::pop_random() {

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