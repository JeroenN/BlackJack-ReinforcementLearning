#ifndef ACTIONSELECTION_H
#define ACTIONSELECTION_H
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include "q-learning.h"
Action selectActionEpsilonGreedy(std::vector<stateActionPair> qValues, int playerCardValue, int dealerCardValue);

#endif // ACTIONSELECTION_H
