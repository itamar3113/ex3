//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include <iostream>


/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};

class Mtmchkin {
private:
    //TODO: complete the Mtmchkin class.
    GameStatus m_gameStatus;
    int m_nextCard;
    int m_numOfCards;
    Card* m_cardsArray;
    Player m_player;

public:

    const int MAX_LEVEL = 10; // should be here?
    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, Card* cardsArray, int numOfCards);

    /*
     * Copy C'tor of the game:
    */
    Mtmchkin(const Mtmchkin&);

    /*
     * Assignment oprator of the game:
    */
    Mtmchkin& operator=(const Mtmchkin& other);
    
    /*
     * Destructor of the game:
    */
    ~Mtmchkin();
    
    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();


    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;
     
    /*
     *  Set the status of the game:
     *
     *  set the member m_statusGame according to the current data of the player
     */
    void setGameStatus();

    //TODO: complete the Mtmchkin class.

};


#endif //EX2_GAME_H
