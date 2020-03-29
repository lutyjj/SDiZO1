#pragma once
class TestArray {
public:
	void startTest();
	TestArray(int arraySize, int timesToRepeat, int timesToAct);
	void setPreferences(int arraySize, int timesToRepeat, int timesToAct);
private:
	int timesToRepeat;
	int arraySize;
	int timesToAct;
};

