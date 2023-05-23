#include <iostream>
#include <stack>
#include "SmartTeam.hpp"
#include <math.h>
#include <string.h>

using namespace std;
namespace ariel
{

    SmartTeam:: SmartTeam(): Team()
    {
    }
    SmartTeam::SmartTeam(Character *lead):Team(lead)
    {
    }

    SmartTeam::~SmartTeam() 
    {
    }

    Character *SmartTeam::find(Team *other)
    {
        Character *toAttack;
        int biggest = -2147483647;
        for (unsigned long int i = 0; i < other->getCount(); i++)
        {
            if (other->getChar(i)->isAlive())
            {
                if (biggest > other->getChar(i)->getPoints())
                {
                    toAttack = other->getChar(i);
                    biggest = other->getChar(i)->getPoints();
                }
            }
        }
        return toAttack;
    }
    void SmartTeam::attack(Team *other)
    {
        cout << "in attack" << endl;
        if(other == nullptr )
            throw invalid_argument("nullptr");
         
        if (this->stillAlive() == 0){
            throw std::runtime_error("Dead team cannot attack");    
        }
        if (other->stillAlive() == 0){
            throw std::runtime_error("Cannot attack dead team");    
        }
        Character *toAttack;

        if (!this->getLeader()->isAlive())
        {
            Character *save;
            int lowest = 2147483647;
            for (unsigned long int i = 0; i < this->getCount(); i++)
            {
                if (this->getChar(i)->isAlive())
                {
                    if (lowest > this->getLeader()->distance(this->getChar(i)))
                    {
                        save = this->getChar(i);
                        lowest = this->getLeader()->distance(this->getChar(i));
                    }
                }
            }
            this->setLeader(save);
        }
        toAttack = find(other);
        for (unsigned long int i = 0; i < this->getCount(); i++)
        {
            if (this->getChar(i)->isAlive() && strcmp((this->getChar(i)->getType()), "C") == 0)
            {
                if (((Cowboy *)this->getChar(i))->hasboolets())
                {
                    ((Cowboy *)this->getChar(i))->shoot(toAttack);
                    if (!toAttack->isAlive())
                    {
                        cout << toAttack->getName() + " died" << endl;
                        if (other->stillAlive() == 0)
                            return;
                        toAttack = find(other);
                    }
                }
                else
                    ((Cowboy *)this->getChar(i))->reload();
            }
            if (this->getChar(i)->isAlive() && strcmp((this->getChar(i)->getType()), "N") == 0)
            {
                if (this->getChar(i)->distance(toAttack) < 1)
                {
                    ((Ninja *)this->getChar(i))->slash(toAttack);
                    if (!toAttack->isAlive())
                    {
                        if (other->stillAlive() > 0)
                            return;
                        toAttack = find(other);
                    }
                }
                else
                    ((Ninja *)this->getChar(i))->move(toAttack);
            }
        }
    }
    void SmartTeam::print()
    {
        cout << "SmartTeam:" << endl;
        for (unsigned long int i = 0; i < this->getCount(); i++)
        {
            cout << this->getChar(i)->print() << endl;
        }
    }
}

