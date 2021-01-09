#include "q-learning.h"
std::vector<StateActionPair> initializeQValues()
{
    std::vector<StateActionPair> qValues;
    //possible values a the algorithm can get, starting at 2 ending at 20;
    for (int playerCardValue = 2; playerCardValue <= 20; ++playerCardValue)
    {
        /************** still have to think about when algorithm interprets ace as 1 and when as 11 *****************/
        //Possible values for dealer
        for (int dealerCardValue = 2; dealerCardValue <= 11; ++dealerCardValue)
        {
            //If actionType = 0 then hit, if action type = 1 then stand
            for (int actionType = 0; actionType <= 1; ++actionType)
            {
                StateActionPair qValue;
                qValue.dealerCardValue = dealerCardValue;
                qValue.playerCardValue = playerCardValue;
                qValue.qValue = 0;
                if (actionType == 0)
                    qValue.action = hit;
                else
                    qValue.action = stand;

                qValues.push_back(qValue);
            }
        }
    }
    return qValues;
}

std::vector<StateActionPair> updateQValue(std::vector<StateActionPair> qValues, StateActionPair currentStateActionPair, StateActionPair nextStateActionPair,
                                          int reward, int indexCurrentStateActionPair)
{
    double alpha = 0.2;
    double gamma = 0.2;

    qValues[indexCurrentStateActionPair].qValue = currentStateActionPair.qValue + alpha *
                                                 (reward + gamma * nextStateActionPair.qValue - currentStateActionPair.qValue);
    return qValues;
}
