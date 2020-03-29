#include "TestArray.h"
#include "Timer.h"
#include "Array.h"
#include <random>
#include <fstream>
#include <iostream>

TestArray::TestArray(int arraySize, int timesToRepeat, int timesToAct) {
	this->timesToRepeat = timesToRepeat;
	this->arraySize = arraySize;
	this->timesToAct = timesToAct;
}

void TestArray::setPreferences(int arraySize, int timesToRepeat, int timesToAct) {
	this->timesToRepeat = timesToRepeat;
	this->arraySize = arraySize;
	this->timesToAct = timesToAct;
}

void TestArray::startTest() {
	Timer timer;
	Array array;
	std::ofstream log;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2000);

	log.open("ArrayTest/ArrayTest_PopBack.txt", std::ios_base::app);
	if (log) {
		log << "Array size: " << arraySize << "\n";
		for (int n = 0; n < timesToRepeat; n++) {
			array.fill_random(arraySize);
			for (int k = 0; k < timesToAct; k++) {
				timer.start();
				array.pop_back();
				timer.stop();
				log << timer.timeElapsed << std::endl;
			}
		}

		log.close();
	}
	else {
		std::cout << "Can't create file. Check if folder \"ListTest\" exists. Create if not. \n";
		return;
	}

	log.open("ArrayTest/ArrayTest_PopFront.txt", std::ios_base::app);
	log << "Array size: " << arraySize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		array.fill_random(arraySize);
		for (int k = 0; k < timesToAct; k++) {
			timer.start();
			array.pop_front();
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ArrayTest/ArrayTest_PopAt.txt", std::ios_base::app);
	log << "Array size: " << arraySize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		array.fill_random(arraySize);
		for (int k = 0; k < timesToAct; k++) {
			int random_number = dist(rng);
			timer.start();
			array.pop_at(random_number);
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ArrayTest/ArrayTest_PushBack.txt", std::ios_base::app);
	log << "Array size: " << arraySize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		array.fill_random(arraySize);
		for (int k = 0; k < timesToAct; k++) {
			timer.start();
			array.push_back(dist(rng));
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ArrayTest/ArrayTest_PushFront.txt", std::ios_base::app);
	log << "Array size: " << arraySize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		array.fill_random(arraySize);
		for (int k = 0; k < timesToAct; k++) {
			timer.start();
			array.push_front(dist(rng));
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();

	log.open("ArrayTest/ArrayTest_PushAt.txt", std::ios_base::app);
	log << "List size: " << arraySize << "\n";
	for (int n = 0; n < timesToRepeat; n++) {
		array.fill_random(arraySize);
		for (int k = 0; k < timesToAct; k++) {
			int random_number = dist(rng);
			timer.start();
			array.push_at(random_number, random_number);
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}
	}

	log.close();
}