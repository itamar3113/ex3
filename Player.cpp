#include "Player.h"


static int initForce(int force)
{
    if (force < 0)
    {
        force = 5;
    }
    return force;
}

static int initMaxHP(int maxHP)
{
    if (maxHP <= 0)
    {
        maxHP = 5;
    }
    return maxHP;
}

Player::Player(const char *name, int force, int maxHP):
    m_name(name),
    m_coins(0),
    m_level(1),
    m_force(initForce(force)),
    m_maxHP(initMaxHP(maxHP)),
    m_HP(m_maxHP)
{}

void Player::printInfo() const
{
    printPlayerInfo(this->m_name, this->m_level, this->m_force, this->m_HP, this->m_coins);
}

void Player::levelUp()
{
    if (this->m_level < 10)
    {
        this->m_level += 1;
    }
}

int Player::getLevel() const
{
    return this->m_level;
}

void Player::buff(int amount)
{
    if (amount > 0)
    {
        this->m_force += amount;
    }
}

void Player::heal(int amount)
{
    if (amount > 0)
    {
        if (this->m_HP + amount <= this->m_maxHP)
        {
            this->m_HP += amount;
        }
        else
        {
            this->m_HP = this->m_maxHP;
        }
    }
}

void Player::damage(int amount)
{
    if (amount > 0)
    {
        if (this->m_HP - amount > 0)
        {
            this->m_HP -= amount;
        }
        else
        {
            this->m_HP = 0;
        }
    }
}

bool Player::isKnockedOut() const
{
    return this->m_HP;
}

void Player::addCoins(int amount)
{
    if (amount > 0)
    {
        this->m_coins += amount;
    }
}

bool Player::pay(int amount)
{
    if(amount < 0)
    {
        return true;
    }
    if (this->m_coins - amount >= 0)
    {
        this->m_coins -= amount;
        return true;
    }
    return false;
}

int Player::getAttackStrength() const
{
    return this->m_force + this->m_level;
}