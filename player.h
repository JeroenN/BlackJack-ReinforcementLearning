#pragma once
#include "deck.h"

class Player {
private:
	vector<int>hand;
public:
	void Hit();
	void Stand();
	void Double();
	void Split();
	int CheckHand();
	char choice();
};
