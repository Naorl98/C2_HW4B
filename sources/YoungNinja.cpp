#include <iostream>
#include <stack>
#include "YoungNinja.hpp"
#include <math.h>
using namespace std;
namespace ariel{   

    YoungNinja::YoungNinja(): Ninja(100, 14){
    }
    YoungNinja::YoungNinja(string name, Point location): Ninja(name, location, 100, 14){
    }     
}