#include "actionSelection.h"
#include "q-learning.h"

Action selectActionEpsilonGreedy(std::vector<stateActionPair> qValues, int playerCardValue, int dealerCardValue)
{
    double epsilon = 0.1;
    double maxEstimate = 0;
    Action action;
    double randomValue = ((double) rand() / (RAND_MAX)); //Value between 0 and 1

    if (randomValue > epsilon)  //explotiative move
    {
        for (size_t i = 0; i < qValues.size(); ++i)
        {
            if (playerCardValue == qValues[i].playerCardValue && dealerCardValue == qValues[i].dealerCardValue)
            {
                double estimateValue = qValues[i].qValue;
                if (estimateValue > maxEstimate)
                {
                    action = qValues[i].action;
                    maxEstimate = estimateValue;
                }
            }
        }
    }
    else //Explorative move
    {
        //50% chance to hit 50% change to stand
        randomValue = ((double) rand() / (RAND_MAX));
        if (randomValue <= 0.5)
            action = hit;
        else
            action = stand;
    }
    return action;
}
