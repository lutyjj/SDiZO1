#include <iostream>
#include "List.h"

void List::display() {
	ElemList* tmp = head;
	while (tmp) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

void List::push_front(int value) {
	ElemList* p = new ElemList;
	p->data = value;
	p->next = head;
	if (head) head->prev = p;
	head = p;
}

void List::pop_front() {
	if (head) {
		ElemList* p = head;
		head = head->next;
		delete p;
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
}