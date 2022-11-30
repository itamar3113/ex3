#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
    this->m_gameStatus = GameStatus::MidGame;
    this->m_nextCard = 0;
    this->m_numOfCards = numOfCards;
    this->m_cardsArray = cardsArray;
    this->m_player = new Player(playerName);
}

void Mtmchkin::playNextCard()
{
    if(this->m_nextCard == m_numOfCards)
    {
        this->m_nextCard = 0;
    }
    this->m_cardsArray[this->m_nextCard].printInfo();
    this->m_cardsArray[this->m_nextCard].applyEncounter(*m_player);
    (*m_player).printInfo();
    this->m_nextCard++;
}