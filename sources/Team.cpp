#include <iostream>
#include <stack>
#include <string.h>
#include "Team.hpp"
#include <math.h>
using namespace std;
namespace ariel
{

    Team::Team()
    {
        count = 0;
    }
    Team::Team(Character *lead)
    {
        if(lead->ifinTeam())
            throw std::runtime_error("Character is already in a team");            
        leader = lead;
        count = 1;
        characters.push_back(lead);
    }
    Team::~Team()
    {
        for (unsigned long int i = 0; i < count; i++)
        {
            characters.pop_back();
        }
    }
    void Team::add(Character *other)
    {  
        if(other->ifinTeam())
            throw std::runtime_error("Character is already in a team");             
   
        if (count >= 10)
            throw std::runtime_error("Team is full");    
        if(count == 0)
            leader = other;
        characters.push_back(other);
        count++;
        cout << "ss:" << endl;

        
    }
    void Team::setLeader(Character * other)
    {
        leader = other;
    }
    void Team::print()
    {
        cout << "Team:" << endl;
        for (size_t i = 0; i < characters.size(); i++)
        {
            if (strcmp((characters[i]->getType()), "C") == 0)
            {
                cout << characters[i]->print() << endl;
            }
        }
        for (size_t i = 0; i < characters.size(); i++)
        {
            if (strcmp((characters[i]->getType()), "N") == 0)
            {
                cout << characters[i]->print() << endl;
            }
        }
    }
    int Team::stillAlive()
    {
        int sum = 0;
        for (unsigned long int i = 0; i < characters.size(); i++)
        {
            if (characters[i]->isAlive())
            {
                sum++;
            }
        }
        return sum;
    }
    Character *Team::getLeader()
    {
        return leader;
    }
    Character *Team::find(Team *other)
    {
        Character *toAttack;
        double lowest = 2147483647;
       
        for (unsigned long int n = 0; n < other->getCount(); n++)
        {
            if (other->getChar(n)->isAlive() && strcmp((other->getChar(n)->getType()), "C") == 0)
            {

                if (lowest > other->getChar(n)->distance(leader))
                {
                    toAttack = other->getChar(n);
                    lowest = other->getChar(n)->distance(leader);
                }
            }
        }
        for (unsigned long int j = 0; j < other->getCount(); j++)
        {
            if (other->getChar(j)->isAlive() && strcmp((other->getChar(j)->getType()), "N") == 0)
            {
                if (lowest > other->getChar(j)->distance(leader))
                {
                    toAttack = other->getChar(j);
                    lowest = other->getChar(j)->distance(leader);
                }
            }
        }
        return toAttack;
    }
    int Team::getCount()
    {
        return count;
    }

    Character *Team::getChar(unsigned long int index)
    {
        return characters[index];
    }

    void Team::attack(Team *other)
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
        vector<Character *> cowboys;
        vector<Character *> ninjas;
        for (unsigned long int i = 0; i < count; i++)
        {
            if(strcmp((characters[i]->getType()), "N") == 0)
                ninjas.push_back(characters[i]);

            if(strcmp((characters[i]->getType()), "C") == 0)
                cowboys.push_back(characters[i]);
        }
        characters.clear();
        for (unsigned long int i = 0; i < cowboys.size(); i++)
        {
            characters.push_back(cowboys[i]);
        }
        for (unsigned long int j = 0; j < ninjas.size(); j++)
        {
            characters.push_back(ninjas[j]);
        }
        cowboys.clear();
        ninjas.clear();
        Character *toAttack;

        if (!leader->isAlive())
        {
            Character *save;
            int lowest = 2147483647;
            for (unsigned long int i = 0; i < count; i++)
            {
                if (characters[i]->isAlive())
                {
                    if (lowest > leader->distance(characters[i]))
                    {
                        save = characters[i];
                        lowest = leader->distance(characters[i]);
                    }
                }
            }
            leader = save;
        }
        toAttack = find(other);

        for ( unsigned long int i = 0; i < count; i++)
        {
            if (characters[i]->isAlive() && strcmp((characters[i]->getType()), "C") == 0)
            {
                if (((Cowboy *)characters[i])->hasboolets())
                {
                    ((Cowboy *)characters[i])->shoot(toAttack);

                    if (!toAttack->isAlive())
                    {
                        cout << toAttack->getName() + " died" << endl;
                        if (other->stillAlive() == 0)
                            return;
                        toAttack = find(other);
                    }

                }
                else
                    ((Cowboy *)characters[i])->reload();
            }
            if (characters[i]->isAlive() && strcmp((characters[i]->getType()), "N") == 0)
            {
                if (characters[i]->distance(toAttack) < 1)
                {
                    ((Ninja *)characters[i])->slash(toAttack);

                    if (!toAttack->isAlive())
                    {
                        if (other->stillAlive() == 0)
                            return;
                        toAttack = find(other);
                    }
             
                }
                else
                    ((Ninja *)characters[i])->move(toAttack);
            }
        }
    }
}
