#ifndef EX3_HEALTH_POINTS_H
#define EX3_HEALTH_POINTS_H

#include <iostream>
#include <string>

const int DEFAULT_MAX_HP = 100;

class HealthPoints
{
    public:
    
    /*
    C'tor of HealthPoints class.
    The player start in m_maxHP health points.
    If it get's illegal values, the player will get the default value for m_maxHP = 100.
    @param m_maxHP - the max m_HP value of the player.
    @return a new istance of HealthPoints.
     */
     // todo should be explicit?? the test demand convertion from int
    HealthPoints (int maxHP = DEFAULT_MAX_HP);

    /*
    * copy c'tor oh Health Points
    */
    HealthPoints(const HealthPoints&);

    /*
    * class for exeptions
    */
    class InvalidArgument {} ;
    
    /*
    * plus and minus operators used as usual between the health points
    * expect that the maximun value is maxHP and the minimum value is 0 
    */
    
    HealthPoints& operator+=(int add);
    HealthPoints& operator-=(int sub);
    
    private:
    int m_maxHP;
    int m_HP;

    friend bool operator==(const HealthPoints&, const HealthPoints&);
    friend bool operator<(const HealthPoints&, const HealthPoints&);
    friend std::ostream& operator<<(std::ostream&, const HealthPoints&);

};

HealthPoints operator+(const HealthPoints&, const int add);
HealthPoints operator-(const HealthPoints&, const int sub);
HealthPoints operator+(const int add, const HealthPoints&);
bool operator!=(const HealthPoints&, const HealthPoints&);
bool operator<=(const HealthPoints&, const HealthPoints&);
bool operator>=(const HealthPoints&, const HealthPoints&);
bool operator>(const HealthPoints&, const HealthPoints&);

#endif