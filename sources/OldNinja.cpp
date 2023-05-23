#include <iostream>
#include <stack>
#include "OldNinja.hpp"
#include <math.h>
using namespace std;
namespace ariel{   

    OldNinja::OldNinja(): Ninja(150, 8){
    }
    OldNinja::OldNinja(string name, Point location): Ninja(name, location, 150, 8){
    }     
}