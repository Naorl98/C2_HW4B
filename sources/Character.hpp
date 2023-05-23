#ifndef CHARACTER_C
#define CHARACTER_C
#include <string>
#include "Point.hpp"
namespace ariel
{

    using namespace std;
    class Character
    {
    public:
        Character();
        Character(Point location, int points, string name);
        Character(int points);
        ~Character();
        bool isAlive();
        void setLocation(Point newloc);
        double distance(Character *other);
        void hit(int sum);
        string getName();
        const char * getType();
        void setType(const char* kind);
        int getPoints();
        Point getLocation();
        string print();
        bool ifinTeam();

    private:
        bool in_team;
        const char * Type;
        Point location;
        int points;
        string name;
    };
}
#endif