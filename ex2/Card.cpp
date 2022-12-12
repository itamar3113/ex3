#include "Card.h"

Card::Card (CardType type, const CardStats& stats):
    m_effect(type),
    m_stats(stats)
{}
void Card::applyEncounter(Player& player) const
{
    
    if(m_effect == CardType::Battle)
    {
        bool win = (player.getAttackStrength() >= m_stats.force);
        if (win)
        {
            player.levelUp();
            player.addCoins(this->m_stats.loot);
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
        }
        printBattleResult(win);
    }
    else if(m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }
    else if(player.pay(m_stats.cost)) //m_effect == Heal || Buff
    {
        if(m_effect == CardType::Heal)
        {   
            player.heal(m_stats.heal);
        }
    
        if(m_effect == CardType::Buff)
        {
            player.buff(m_stats.buff);
        }
    }
}
void Card::printInfo() const
{
    if(m_effect == CardType::Battle)
    {
        printBattleCardInfo(this->m_stats);
    }
    else if(m_effect == CardType::Buff)
    {
        printBuffCardInfo(this->m_stats);
    }
    else if(m_effect == CardType::Heal)
    {
        printHealCardInfo(this->m_stats);
    }
    else //(m_effect == Treasure)
    {
        printTreasureCardInfo(this->m_stats);
    }
}
