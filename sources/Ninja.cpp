#include <iostream>
#include <stack>
#include "Ninja.hpp"
#include <math.h>
using namespace std;
namespace ariel{   

    Ninja::Ninja(): Character(){
        this->setType("N");

    }
    Ninja::Ninja(int points, int speed): Character(points), speed(speed){
        this->setType("N");

    }
    Ninja::Ninja(string name, Point location, int points ,int speed): Character(location, points, name), speed(speed){
        this->setType("N");

    }

    void Ninja::slash(Character * other){
        if (this == other)
        {
            throw std::runtime_error("cant slash yourself");
        }
        if(!other->isAlive())
            throw std::runtime_error("Cant slash died people\n");
        if(!this->isAlive())
            throw std::runtime_error("ninja died\n");

        if(this->distance(other) < 1){
            cout << this->getName() + " slash " + other->getName() <<endl;
            other->hit(40);
        }

    }
    void Ninja::move(Character * other){
        int dist = speed;
        if(this->distance(other)<speed)
            this->setLocation(Point(other->getLocation().GetX(), other->getLocation().GetY()));
        else
            this->setLocation(this->getLocation().moveTowards(this->getLocation(), other->getLocation(), (double)speed));
        cout << this->getName() + " Move to: "<< this->getLocation().GetX() << ", " << this->getLocation().GetY() << endl;
    }          
}