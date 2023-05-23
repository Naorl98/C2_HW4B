#ifndef YNINJA
#define YNINJA
#include <string>
#include "Ninja.hpp"
namespace ariel{

    using namespace std;
    class YoungNinja : public Ninja
    { 
    public:
        YoungNinja();
        YoungNinja(string name, Point location);   
    };
}
#endif