#ifndef EX2_Player_H
#define EX2_Player_H

#include <iostream>
#include <string>

class Player
{
private:
    char *name;
    int level;
    int force;
    int maxHP;
    int HP;
    int coins;

public:
    /*
    Creator of Player class.
    The player start in level 1, with 0 coins, and the initial HP is maxHP.
    If it get's illegal values, the player will get the default values(force = 5, maxHP = 100).
    @param name - the name of tje player.
    @param force - the initial force of the player.
    @param maxHP - the max HP value of the player.
    @return a ne istance of player.
     */
    // todo how to declare name.
    Player(char* name, int force, int maxHP);

    //todo check the default.
    /*
    A copy constructor.
    */
    Player(const Player &) = default;

    /*
    Destructor
    */
    ~Player() = default;

    Player &operator=(const Player &other) = default;

    /*
    Print the Player information.
    */
    void printInfo() const;

    /*
    Raises the player's level by one.
    */
    void levelUp();

    /*
    @return - the level of theplayer
    */
    int getLevel() const;

    /*
    Raises the player's force in the amount received as an argument.
    @param amount - the amount to raise the force.
    */
    void buff(int amount);

    /*
   Raises the player's HP in the amount received as an argument, up to the maxHP.
   @param amount - the amount to raise the HP.
   */
    void hael(int amount);

    /*
    Drops the player's HP in the amount received as an argument.
    @param amount - the amount to drop the HP.
    */
    void damage(int amount);

    /*
    @return - True if HP > 0,
              False otherwise.
    */
    bool isKnockedOut() const;

    /*
    Add coins to the player in the amount received as an argument.
    @param the amount to add to coins
    */
    void addCoins(int amount);

    /*
    Reduce coins from the player in the amount received as an argument.
    @param the amount to add to coins
    @return - True if the player have enough coins,
              False otherwise.
    */
    bool pay(int amount);

    /*
    @return player's force + level
    */
    int getAttackStrength() const;
};

#endif