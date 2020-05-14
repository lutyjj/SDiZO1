#pragma once
class TestBinaryHeap {
public:
	void startTest();
	TestBinaryHeap(int heapSize, int timesToRepeat, int timesToAct);
	void setPreferences(int heapSize, int timesToRepeat, int timesToAct);
private:
	int timesToRepeat;
	int heapSize;
	int timesToAct;
};