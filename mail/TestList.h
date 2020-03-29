#pragma once
class TestList {
public:
	void startTest();
	TestList(int listSize, int timesToRepeat, int timesToAct);
	void setPreferences(int listSize, int timesToRepeat, int timesToAct);
private:
	int timesToRepeat;
	int listSize;
	int timesToAct;
};

