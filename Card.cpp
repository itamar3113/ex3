#include "Card.h"

Card::Card (CardType type, const CardStats& stats)
{
    this->m_effect = type;
    this->m_stats = stats;
}
void Card::applyEncounter(Player& player) const
{
    
    if(m_effect == Battle)
    {
        bool win = (player.getAttackStrength() >= m_stats->force);
        if (win)
        {
            player.levelUp();
            player.addCoins(m_stats->loot);
        }
        else
        {
            player.damage(m_stats->hpLossOnDefeat);
        }
        printBattleResult(win);
    }
    else if(m_effect == CardType::Treasure)
    {
        player.addCoins(m_stats->loot);
    }
    else if(player.pay(m_stats->cost)) //m_effect == Heal || Buff
    {
        if(m_effect == CardType::Heal)
        {   
            player.heal(m_stats->heal);
        }
    
        if(m_effect == CardType::Buff)
        {
            player.buff(m_stats->buff);
        }
    }
    void printInfo() const
    {
        if(m_effect == CardType::Battle)
        {
            this.printBattleCardInfo();
        }
        else if(m_effect == CardType::Buff)
        {
            this.printBuffCardInfo();
        }
        else if(m_effect == CardType::Heal)
        {
            this.printHealCardInfo();
        }
        else //(m_effect == Treasure)
        {
            this.printTreasureCardInfo();
        }
    }
}
