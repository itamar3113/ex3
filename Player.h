#ifndef EX2_Player_H
#define EX2_Player_H

#include <iostream>
#include <string>
#include "utilities.h"

class Player
{
private:
    char *m_name;
    int m_coins;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;

public:
    /*
    Creator of Player class.
    The player start in m_level 1, with 0 m_coins, and the initial m_HP is m_maxHP.
    If it get's illegal values, the player will get the default values(m_force = 5, m_maxHP = 100).
    @param m_name - the m_name of tje player.
    @param m_force - the initial m_force of the player.
    @param m_maxHP - the max m_HP value of the player.
    @return a ne istance of player.
     */
    // todo how to declare m_name.
    Player(const char* m_name, int maxHP = 100, int force = 5);

    /*
    A copy constructor.
    */
    Player(const Player &);

    /*
    Destructor
    */
    ~Player();

    Player &operator=(const Player &other);

    /*
    Print the Player information.
    */
    void printInfo() const;

    /*
    Raises the player's m_level by one.
    */
    void levelUp();

    /*
    @return - the m_level of theplayer
    */
    int getLevel() const;

    /*
    Raises the player's m_force in the amount received as an argument.
    @param amount - the amount to raise the m_force.
    */
    void buff(int amount);

    /*
   Raises the player's m_HP in the amount received as an argument, up to the m_maxHP.
   @param amount - the amount to raise the m_HP.
   */
    void heal(int amount);

    /*
    Drops the player's m_HP in the amount received as an argument.
    @param amount - the amount to drop the m_HP.
    */
    void damage(int amount);

    /*
    @return - True if m_HP = 0,
              False otherwise.
    */
    bool isKnockedOut() const;

    /*
    Add m_coins to the player in the amount received as an argument.
    @param the amount to add to m_coins
    */
    void addCoins(int amount);

    /*
    Reduce m_coins from the player in the amount received as an argument.
    @param the amount to add to m_coins
    @return - True if the player have enough m_coins,
              False otherwise.
    */
    bool pay(int amount);

    /*
    @return player's m_force + m_level
    */
    int getAttackStrength() const;
};

#endif