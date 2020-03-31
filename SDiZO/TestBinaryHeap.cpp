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

	auto totalActions = timesToAct * timesToRepeat;

	log.open("BinaryHeapTest/BinaryHeapTest_Pop.txt", std::ios_base::app);
	if (log) {
		long double counter = 0;
		log << "BinaryHeap size: " << heapSize << "\n";
		log << "Total elements tested: " << timesToAct * timesToRepeat << "\n";

		for (int n = 0; n < timesToRepeat; n++) {
			binaryHeap.fillRandom(heapSize);
			for (int k = 0; k < timesToAct; k++) {
				timer.start();
				binaryHeap.pop();
				timer.stop();
				log << timer.timeElapsed << std::endl;
				counter = timer.timeElapsed + counter;
			}
		}

		std::cout << "Tested size: " << heapSize << std::endl;
		std::cout << "Total elements tested: " << totalActions << std::endl;
		std::cout << "Avg. time: " << counter / totalActions << " [ms]" << std::endl;

		log << "Avg.time: " << counter / (timesToAct * timesToRepeat) << "[ms]" << "\n";
	}
	else {
		std::cout << "Can't create file. Check if folder \"BinaryHeapTest\" exists. Create if not. \n";
		return;
	}

	log.close();


	log.open("BinaryHeapTest/BinaryHeapTest_Push.txt", std::ios_base::app);
	if (log) {
		long double counter = 0;
		log << "BinaryHeap size: " << heapSize << "\n";
		log << "Total elements tested: " << timesToAct * timesToRepeat << "\n";

		for (int n = 0; n < timesToRepeat; n++) {
			binaryHeap.fillRandom(heapSize);
			for (int k = 0; k < timesToAct; k++) {
				int random_number = dist(rng);
				timer.start();
				binaryHeap.push(random_number);
				timer.stop();
				log << timer.timeElapsed << std::endl;
				counter = timer.timeElapsed + counter;
			}
		}

		std::cout << "Tested size: " << heapSize << std::endl;
		std::cout << "Total elements tested: " << totalActions << std::endl;
		std::cout << "Avg. time: " << counter / totalActions << " [ms]" << std::endl;

		log << "Avg.time: " << counter / (timesToAct * timesToRepeat) << "[ms]" << "\n";
	}
	else {
		std::cout << "Can't create file. Check if folder \"BinaryHeapTest\" exists. Create if not. \n";
		return;
	}

	log.close();

	log.open("BinaryHeapTest/BinaryHeapTest_Search.txt", std::ios_base::app);
	if (log) {
		long double counter = 0;
		log << "BinaryHeap size: " << heapSize << "\n";
		log << "Total elements tested: " << timesToAct * timesToRepeat << "\n";

		for (int n = 0; n < timesToRepeat; n++) {
			binaryHeap.fillRandom(heapSize);
			for (int k = 0; k < timesToAct; k++) {
				int random_number = dist(rng);
				timer.start();
				binaryHeap.search(random_number);
				timer.stop();
				log << timer.timeElapsed << std::endl;
				counter = timer.timeElapsed + counter;
			}
		}

		std::cout << "Tested size: " << heapSize << std::endl;
		std::cout << "Total elements tested: " << totalActions << std::endl;
		std::cout << "Avg. time: " << counter / totalActions << " [ms]" << std::endl;

		log << "Avg.time: " << counter / (timesToAct * timesToRepeat) << "[ms]" << "\n";
	}
	else {
		std::cout << "Can't create file. Check if folder \"BinaryHeapTest\" exists. Create if not. \n";
		return;
	}

	log.close();
}