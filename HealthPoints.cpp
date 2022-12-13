#include "HealthPoints.h"

static int init(int maxHP)
{
    if(maxHP <= 0)
    {
        throw HealthPoints::InvalidArgument();
    }
    return maxHP;
}

HealthPoints::HealthPoints(int maxHP):
                                m_maxHP(init(maxHP)),
                                m_HP(init(maxHP))
                                {}

HealthPoints::HealthPoints(const HealthPoints& HP1): m_maxHP(HP1.m_maxHP),
                                                    m_HP(HP1.m_HP)
                                                    {}


HealthPoints& HealthPoints::operator+=(int add)
{
    if(m_HP + add > m_maxHP)
    {
        m_HP = m_maxHP;
    }
    else
    {
        m_HP = m_HP + add;
    }
    return (*this);
}

HealthPoints& HealthPoints::operator-=(int sub)
{
    if(m_HP - sub < 0)
    {
        m_HP = 0;
    }
    else
    {
        m_HP = m_HP - sub;
    }
    return (*this);
}

bool operator==(const HealthPoints& HP1, const HealthPoints& HP2)
{
    return HP1.m_HP == HP2.m_HP;
}
bool operator<(const HealthPoints& HP1, const HealthPoints& HP2)
{
    return HP1.m_HP < HP2.m_HP;
}


HealthPoints operator+(const HealthPoints& HP1, const int add)
{
    HealthPoints result(HP1);
    result += add;
    return result;
}

HealthPoints operator+(const int add, const HealthPoints& HP1)
{
    HealthPoints result(HP1);
    result += add;
    return result;
}

HealthPoints operator-(const HealthPoints& HP1, const int sub)
{
    HealthPoints result(HP1);
    result -= sub;
    return result;
}
bool operator!=(const HealthPoints& HP1, const HealthPoints& HP2)
{
    return !(HP1 == HP2);
}
bool operator<=(const HealthPoints& HP1, const HealthPoints& HP2)
{
    return (HP1 == HP2 || HP1 < HP2);
}
bool operator>=(const HealthPoints& HP1, const HealthPoints& HP2)
{
    return !(HP1 < HP2);
}
bool operator>(const HealthPoints& HP1, const HealthPoints& HP2)
{
    return (!(HP1 == HP2) && !(HP1 < HP2));
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& HP)
{
    os << HP.m_HP << "(" << HP.m_maxHP << ")";
    return os;
}