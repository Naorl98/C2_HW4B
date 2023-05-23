#ifndef STEAM
#define STEAM
#include <string>
#include "Team.hpp"

namespace ariel
{

    using namespace std;
    class SmartTeam : public Team
    {
    public:
        SmartTeam();
        SmartTeam(Character * leader);
        ~SmartTeam();;
        Character * find(Team * other) override;
        void print() override;
        void attack(Team * other) override;

    private:
    };
}
#endif