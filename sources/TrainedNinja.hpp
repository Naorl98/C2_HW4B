#ifndef TNINJA
#define TNINJA
#include <string>
#include "Ninja.hpp"
namespace ariel{

    using namespace std;
    class TrainedNinja : public Ninja
    { 
    public:
        TrainedNinja();
        TrainedNinja(string name, Point location);   
    };
}
#endif