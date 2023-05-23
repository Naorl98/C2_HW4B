#ifndef COWBOY
#define COWBOY
#include <string>
#include "Character.hpp"
namespace ariel{

    using namespace std;
    class Cowboy : public Character{ 
    public:
        Cowboy();
        Cowboy(string name, Point location);
        void shoot(Character * other);
        bool hasboolets();
        void reload();

    private:
        int boolets;

            
    };
}
#endif