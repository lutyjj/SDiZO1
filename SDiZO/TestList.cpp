#include "TestList.h"
#include "Timer.h"
#include "List.h"
#include <random>
#include <fstream>
#include <iostream>

TestList::TestList(int listSize, int timesToRepeat, int timesToAct) {
	this->timesToRepeat = timesToRepeat;
	this->listSize = listSize;
	this->timesToAct = timesToAct;
}

void TestList::setPreferences(int listSize, int timesToRepeat, int timesToAct) {
	this->timesToRepeat = timesToRepeat;
	this->listSize = listSize;
	this->timesToAct = timesToAct;
}

void TestList::startTest() {
	Timer timer;
	List list;
	std::ofstream log;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2000);

	log.open("ListTest/ListTest_PopBack", std::ios_base::app);
	log << "List size: " << listSize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		list.fill_random(listSize);
		for (int k = 0; k < timesToAct; k++) {
			timer.start();
			list.pop_back();
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ListTest/ListTest_PopFront.txt", std::ios_base::app);
	log << "List size: " << listSize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		list.fill_random(listSize);
		for (int k = 0; k < timesToAct; k++) {
			timer.start();
			list.pop_front();
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ListTest/ListTest_PopAt.txt", std::ios_base::app);
	log << "List size: " << listSize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		list.fill_random(listSize);
		for (int k = 0; k < timesToAct; k++) {
			int random_number = dist(rng);
			timer.start();
			list.pop_at(random_number);
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ListTest/ListTest_PushBack.txt", std::ios_base::app);
	log << "List size: " << listSize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		list.fill_random(listSize);
		for (int k = 0; k < timesToAct; k++) {
			timer.start();
			list.push_back(dist(rng));
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ListTest/ListTest_PushFront.txt", std::ios_base::app);
	log << "List size: " << listSize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		list.fill_random(listSize);
		for (int k = 0; k < timesToAct; k++) {
			timer.start();
			list.push_front(dist(rng));
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ListTest/ListTest_PushAt.txt", std::ios_base::app);
	log << "List size: " << listSize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		list.fill_random(listSize);
		for (int k = 0; k < timesToAct; k++) {
			int random_number = dist(rng);
			timer.start();
			list.push_at(random_number, random_number);
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();
	list.clear();
}