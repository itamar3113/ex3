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

Mtmchkin::Mtmchkin(const Mtmchkin& other) : 

    m_gameStatus(other.getGameStatus()),
    m_nextCard(0),
    m_numOfCards(other.m_numOfCards),
    m_cardsArray(new Card[other.m_numOfCards]),
    m_player(Player(other.m_player))
{
    for(int i = 0; i < other.m_numOfCards; i++){
        m_cardsArray[i] = other.m_cardsArray[i];
    }
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] m_cardsArray;
    m_cardsArray = new Card[other.m_numOfCards];
    for(int i = 0; i < other.m_numOfCards; i++){
        m_cardsArray[i] = other.m_cardsArray[i];
    }
    return *this;
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
