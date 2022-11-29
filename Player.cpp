#include "Player.h"

static int initForce(int force)
{
    if (!force || force < 0)
    {
        force = 5;
    }
    return force;
}

static int initMaxHP(int maxHP)
{
    if (!maxHP || maxHP <= 0)
    {
        maxHP = 5;
    }
    return maxHP;
}

Player::Player(char* name, int force, int maxHP)
{
    this->name = name;
    this->coins = 0;
    this->level = 1;
    this->force = initForce(force);
    this->maxHP = initMaxHP(maxHP);
    this->HP = this->maxHP;
}

