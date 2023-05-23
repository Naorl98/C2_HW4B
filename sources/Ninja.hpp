#ifndef NINJA
#define NINJA
#include <string>
#include "Character.hpp"
namespace ariel{

    using namespace std;
    class Ninja : public Character{ 
    public:
        Ninja();
        Ninja(int points, int speed);
        Ninja(string name, Point location, int points ,int speed);
        void move(Character * other);
        void slash(Character * other);
    private:
        int speed;         
    };
}
#endif