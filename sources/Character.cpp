#include <iostream>
#include <stack>
#include "Character.hpp"
#include <math.h>
using namespace std;
namespace ariel{   

    Character::Character(): points(0), in_team(false){
    }
    Character::Character(int points): points(points), in_team(false){
    }
    Character::Character(Point location, int points, string name): location(location), points(points), name(name), in_team(false){
    }
    Character::~Character(){
        location = Point(0,0);
        in_team = false;
        points = 0;
    }

    void Character::setLocation(Point newloc){
        location = Point(newloc.GetX(), newloc.GetY());
    }
    bool Character::ifinTeam(){
        if(in_team)
            return true;
        in_team = true;
        return false;
    }
    bool Character::isAlive(){
        if(points > 0)
            return true;
        return false;
    }
    double Character::distance(Character * other){
        return location.distance(other->getLocation());
    }
    string Character::getName(){
        return name;
    }
    const char * Character::getType(){
        return Type;
    }
    void Character::setType(const char * kind){
        Type = kind;
    }
    int Character::getPoints(){
        return points;
    }
    void Character::hit(int sum){
        if (sum < 0 )
            throw invalid_argument("sum negative");

        int save  = points;
        points -= sum;
        cout << name + " from " << save << " to " << points <<endl;

    }
    Point Character::getLocation(){
        return location;
    }
    string Character::print()
    {
        string prnt = "";
        
        prnt += Type;
        if(points>0)
        {
        prnt += " - name: " + name + "\n";
        prnt += "points: " + to_string(points) + "\n";
        prnt += "Current_location: " + location.print() + "\n";
        }
        else{
            prnt += "(" + name + ")\n";
        }
        return prnt;
            
    }
}