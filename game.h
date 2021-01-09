#pragma once
#include "dealer.h"
#include "q-learning.h"

void addDealer();
void addPlayer();
void start();
void checkWin();
void turn();
std::vector<StateActionPair> updateQValue(std::vector<StateActionPair> qValues, StateActionPair currentStateActionPair, StateActionPair nextStateActionPair,
                                          int reward, int indexCurrentStateActionPair);
