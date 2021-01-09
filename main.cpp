#include<iostream>
#include "game.h"

int main() {
	//Add a Dealer
	addDealer();
	//Add players
	addPlayer();
	//Start game
	start();
	turn();
	checkWin();
	
	system("pause");
}
