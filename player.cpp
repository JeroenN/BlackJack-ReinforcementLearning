#include "player.h"

void Player::Hit() {
	this->hand.push_back(getCard());
}

void Player::Stand() {
	//Stand, do nothing.
}

int Player::CheckHand() {
	int sum = 0;
	for (auto i : this->hand) {
		if (i == 1 && sum + 11 <= 21) i = 11;
		cout << "Card:" << i << endl;
		sum += i;
	}
	return sum;
}

char Player::choice() {
	cout << "Non Blackjack, Hit or Stand?" << endl;
	cout << "Press H to draw a card, press S to stand." << endl;
	char c = ' ';
	cin >> c;
	return c;
}





