#ifndef ONINJA
#define ONINJA
#include <string>
#include "Ninja.hpp"
namespace ariel{

    using namespace std;
    class OldNinja : public Ninja{ 
    public:
        OldNinja();
        OldNinja(string name, Point location);   
    };
}
#endif