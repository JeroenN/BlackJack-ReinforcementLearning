#pragma once
#include "deck.h"
#include "player.h"


class Dealer {
private:
	vector<int>hand;
	vector<Player*>playerSet;
public:
	void setPlayerSet(vector<Player*>& playerSet);
	vector<Player*> getPlayerSet();
	void Distribute();
	void Hit();
	int CheckHand();
    int showFirstCard();
};
