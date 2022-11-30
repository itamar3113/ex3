#include "Mtmchkin.h"
#include "Player.h"
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
    this->player(playerName); 
    this->status = GameStatus::MidGame;
    this->nextCard = 0;
}

void playNextCard()
{
    if(this->nextCard == numOfCards)
    {
        nextCard = 0;
    }
    cardsArray[this->nextCard].printInfo();
    cardsArray[this->nextCard].applyEncounter(player);
    player.printInfo();
    this->nextCard++;
}

