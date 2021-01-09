#include "game.h"
#include "q-learning.h"
#include "actionSelection.h"
#include<string>

vector<Dealer*>dealerSet;
vector<Player*>playerSet;

void addDealer() {
	Dealer* d = new Dealer();
	dealerSet.push_back(d);
}

void addPlayer() {
	Player* d = new Player();
	playerSet.push_back(d);
}

void start() {
	cout << "******Game Start!******"<<endl;
	init_deck();
	print_deck();
	shuffler();
	print_deck();
	Dealer* d = dealerSet.front();
	d->setPlayerSet(playerSet);
	d->Distribute();
}

void checkWin() {
	cout << "******Check Win******" << endl;
	Dealer* d = dealerSet.front();
	int dealerHand=d->CheckHand();
	int player = 0;

	string res = "";
	for (auto p : d->getPlayerSet()) {
		player++;
		cout << "Player" << player << "'s Hand" << endl;
		int playerHand = p->CheckHand();
		if (playerHand == 21 && dealerHand == 21) {
			res += "Player";
			res += (char)(player + '0');
			res+=" Blackjack Push!\n";
		}else
		if (playerHand == 21 && dealerHand != 21) {
			res += "Player";
			res += (char)(player + '0');
			res += " Wins, Blackjack!\n";
		}else
		if(playerHand != 21 && dealerHand == 21) {
			res+= "Dealer Wins, Blackjack!\n";
		}else
		if (playerHand <21 && playerHand > dealerHand) {
			res+= "Player";
			res+= (char)(player + '0');
			res += " Wins!\n";
		}else
		if (playerHand > 21) {
			res+= "Player";
			res+= (char)(player + '0');
			res += " Bust, lose!\n";
		}else
		if (dealerHand > 21) {
			res+= "Dealer Bust, Player Wins!\n";
		}else
		if (playerHand == dealerHand) {
			res += "Player";
			res += (char)(player + '0');
			res+= " Push!\n";
		}else
		if (playerHand < dealerHand) {
			res += "Player";
			res += (char)(player + '0');
			res += " lose!\n";
		}
	}
		cout << res << endl;
}
void findStateActionPair(std::vector<StateActionPair> qValues, StateActionPair &stateActionPair,  int &index, int playerCardValue, int dealerCardValue, Action action)
{

    for (size_t i = 0; i < qValues.size(); ++i)
    {
        if (playerCardValue == qValues[i].playerCardValue && dealerCardValue == qValues[i].dealerCardValue && action == qValues[i].action)
        {
            stateActionPair = qValues[i];
            index = i;
        }
        else //For debug purposes
        {
            std::cout << "Error, this should not happen. There is no matching entry in the lookup table \n";
            std::cout << "DEBUG playercardValue: " << playerCardValue << "\nDEBUG dealercardValue: " << dealerCardValue
                      << "\nDEBUG action: " << action;
        }
    }
}

StateActionPair findStateActionPairWithMaxAction(std::vector<StateActionPair> qValues, int playerCardValue, int dealerCardValue)
{
    StateActionPair stateActionPair;
    double maxQValue = 0;
    for (size_t i = 0; i < qValues.size(); ++i)
    {
        if (playerCardValue == qValues[i].playerCardValue && dealerCardValue == qValues[i].dealerCardValue)
            if (qValues[i].qValue > maxQValue)
            {
                maxQValue = qValues[i].qValue;
                stateActionPair = qValues[i];
            }
    }
    return stateActionPair;
}
void turn() {
	Dealer* d = dealerSet.front();
	int player = 0;
    std::vector<StateActionPair> qValues = initializeQValues();

	for (auto p : d->getPlayerSet()) {
		player++;
		cout << endl;
		cout << "******Player" << player << "'s move*******" << endl;
		cout << "Player" << player << "'s Hand" << endl;
		int playerHand = p->CheckHand();
        int dealerFirstCard = d->showFirstCard();

        Action action = selectActionEpsilonGreedy(qValues, playerHand, dealerFirstCard);
        StateActionPair currentStateActionPair;
        int index;
        findStateActionPair(qValues, currentStateActionPair, index, playerHand, dealerFirstCard, action);

        while (action != stand && playerHand < 21)
        {
            if (action == hit)
                p->Hit();
            playerHand = p->CheckHand();
        }
        StateActionPair nextStateActionPair = findStateActionPairWithMaxAction(qValues, playerHand, dealerFirstCard);

        if (playerHand < 21)
            qValues = updateQValue(qValues, currentStateActionPair, nextStateActionPair, 0, index);
        else if (playerHand == 21)
            qValues = updateQValue(qValues, currentStateActionPair, nextStateActionPair, 1, index);
        else
            qValues = updateQValue(qValues, currentStateActionPair, nextStateActionPair, -1, index);
	}
	cout << "******Turns end!******" << endl;
	while (d->CheckHand() < 17) 
		d->Hit();
}
