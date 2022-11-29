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

Player::Player(const char *name, int force, int maxHP)
{
    this->name = name;
    this->coins = 0;
    this->level = 1;
    this->force = initForce(force);
    this->maxHP = initMaxHP(maxHP);
    this->HP = this->maxHP;
}

void Player::printInfo() const
{
    printPlayerInfo(this->name, this->level, this->force, this->HP, this->coins);
}

void Player::levelUp()
{
    if (this->level < 10)
    {
        this->level += 1;
    }
}

int Player::getLevel() const
{
    return this->level;
}

void Player::buff(int amount)
{
    if (amount > 0)
    {
        this->force += amount;
    }
}

void Player::heal(int amount)
{
    if (amount > 0)
    {
        if (this->HP + amount <= this->maxHP)
        {
            this->HP += amount;
        }
        else
        {
            this->HP = this->maxHP;
        }
    }
}

void Player::damage(int amount)
{
    if (amount > 0)
    {
        if (this->HP - amount > 0)
        {
            this->HP -= amount;
        }
        else
        {
            this->HP = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    return this->HP;
}

void Player::addCoins(int amount)
{
    if (amount > 0)
    {
        this->coins += amount;
    }
}

bool Player::pay(int amount)
{
    if (this->coins - amount >= 0)
    {
        this->coins -= amount;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const
{
    return this->force + this->level;
}