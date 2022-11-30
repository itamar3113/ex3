#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):

    m_gameStatus(GameStatus::MidGame),
    m_nextCard(0),
    m_numOfCards(numOfCards),
    m_cardsArray(cardsArray),
    m_player(Player(playerName))
{}

void Mtmchkin::playNextCard()
{
    if(this->m_nextCard == m_numOfCards)
    {
        this->m_nextCard = 0;
    }
    this->m_cardsArray[this->m_nextCard].printInfo();
    this->m_cardsArray[this->m_nextCard].applyEncounter(m_player);
    m_player.printInfo();
    this->m_nextCard++;
}