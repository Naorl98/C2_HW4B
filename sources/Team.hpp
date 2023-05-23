#ifndef TEAM
#define TEAM
#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
namespace ariel
{

    using namespace std;
    class Team
    {
    public:
        Team();
        Team(Character *leader);
        ~Team();
        int stillAlive();
        virtual void print();
        Character * getLeader();
        virtual Character * find(Team * other);
        int getCount();
        Character * getChar(unsigned long int index);
        virtual void attack(Team *other);
        void add(Character *other);
        void setLeader(Character *leader);
    private:
        vector<Character *> characters;
        Character * leader;  
        int count;

    };
}
#endif