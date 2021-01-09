#ifndef QLEARNING_H
#define QLEARNING_H
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

enum Action
{
    hit,
    stand
};

struct stateActionPair
{
    double qValue;
    int playerCardValue;
    int dealerCardValue;
    Action action;
};

std::vector<stateActionPair> initializeQValues();
std::vector<stateActionPair> updateQValue(std::vector<stateActionPair> qValues, stateActionPair nextState, int playerCardValue, int dealerCardValue,
                                          Action action, int reward);

#endif // QLEARNING_H
