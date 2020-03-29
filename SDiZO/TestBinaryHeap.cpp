#include "TestBinaryHeap.h"
#include "Timer.h"
#include "BinaryHeap.h"
#include <random>
#include <fstream>
#include <iostream>

TestBinaryHeap::TestBinaryHeap(int heapSize, int timesToRepeat, int timesToAct) {
	this->timesToRepeat = timesToRepeat;
	this->heapSize = heapSize;
	this->timesToAct = timesToAct;
}

void TestBinaryHeap::setPreferences(int heapSize, int timesToRepeat, int timesToAct) {
	this->timesToRepeat = timesToRepeat;
	this->heapSize = heapSize;
	this->timesToAct = timesToAct;
}

void TestBinaryHeap::startTest() {
	Timer timer;
	BinaryHeap binaryHeap;
	std::ofstream log;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2000);

	log.open("BinaryHeapTest/BinaryHeapTest_Pop.txt", std::ios_base::app);
	if (log) {
		log << "BinaryHeap size: " << heapSize << "\n";
		binaryHeap.fillRandom(heapSize);
		for (int n = 0; n < timesToRepeat; n++) {
			for (int k = 0; k < timesToAct; k++) {
				timer.start();
				binaryHeap.pop();
				timer.stop();
				log << timer.timeElapsed << std::endl;
			}
		}
		log.close();
	}
	else {
		std::cout << "Can't create file. Check if folder \"BinaryHeapTest\" exists. Create if not. \n";
		return;
	}


	if (log) {
		log.open("BinaryHeapTest/BinaryHeapTest_Push.txt", std::ios_base::app);
		log << "BinaryHeap size: " << heapSize << "\n";
		binaryHeap.fillRandom(heapSize);
		for (int n = 0; n < timesToRepeat; n++)
			for (int k = 0; k < timesToAct; k++) {
				timer.start();
				binaryHeap.push(dist(rng));
				timer.stop();
				log << timer.timeElapsed << std::endl;
			}
	}
	else {
		std::cout << "Can't create file. Check if folder \"BinaryHeapTest\" exists. Create if not. \n";
		return;
	}

	log.close();

	log.open("BinaryHeapTest/BinaryHeapTest_Search.txt", std::ios_base::app);
	log << "BinaryHeap size: " << heapSize << "\n";
	binaryHeap.fillRandom(heapSize);
	for (int n = 0; n < timesToRepeat; n++) 
		for (int k = 0; k < timesToAct; k++) {
			timer.start();
			binaryHeap.push(dist(rng));
			timer.stop();
			log << timer.timeElapsed << std::endl;
		}

	log.close();
}