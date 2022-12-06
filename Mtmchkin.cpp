#include "Mtmchkin.h"


Mtmchkin::Mtmchkin(const char* playerName, Card* cardsArray, int numOfCards):

    m_gameStatus(GameStatus::MidGame),
    m_nextCard(0),
    m_numOfCards(numOfCards),
    m_cardsArray(new Card[numOfCards]),
    m_player(Player(playerName))
{
    for(int i = 0; i<numOfCards;i++){
        m_cardsArray[i] = cardsArray[i];
    }
}

void Mtmchkin::playNextCard()
{
    if(this->m_nextCard == m_numOfCards)
    {
        this->m_nextCard = 0;
    }
    this->m_cardsArray[this->m_nextCard].printInfo();
    this->m_cardsArray[this->m_nextCard].applyEncounter(m_player);
    m_player.printInfo();
    setGameStatus(); // need to be here?
    this->m_nextCard++;
}

bool Mtmchkin::isOver() const
{
    return (getGameStatus() != GameStatus::MidGame);
}

void Mtmchkin::setGameStatus()
{
    if (m_player.getLevel() == MAX_LEVEL)
    {
        m_gameStatus = GameStatus::Win;
    }
    if (m_player.isKnockedOut())
    {
        m_gameStatus = GameStatus::Loss;
    }
}

GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}

Mtmchkin::~Mtmchkin(){
    delete[] m_cardsArray;
}
