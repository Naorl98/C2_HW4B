#include <iostream>
#include <stack>
#include "TrainedNinja.hpp"
#include <math.h>
using namespace std;
namespace ariel{   

    TrainedNinja::TrainedNinja(): Ninja(120, 12){
    }
    TrainedNinja::TrainedNinja(string name, Point location): Ninja(name, location, 120, 12){
    }     
}