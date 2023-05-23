#ifndef TEAM2
#define TEAM2
#include <string>
#include "Team.hpp"

namespace ariel
{

    using namespace std;
    class Team2 : public Team
    {
    public:
        Team2();
        Team2(Character * leader);
        ~Team2();
        Character * find(Team * other) override;
        void print() override;
        void attack(Team * other) override;

    private:
    };
}
#endif