#include <iostream>
#include <stack>
#include "Point.hpp"
#include <math.h>
using namespace std;
namespace ariel
{

    Point::Point()
    {
        this->x_value = 0;
        this->y_value = 0;
    }
    Point::Point(double x_val, double y_val)
    {
        this->x_value = x_val;
        this->y_value = y_val;
    }
    double Point::GetX()
    {
        return x_value;
    }
    double Point::GetY()
    {
        return y_value;
    }
    double Point::distance(Point other)
    {
        double newX = pow((x_value - other.GetX()), 2);
        double newY = pow((y_value - other.GetY()), 2);
        return sqrt((newX + newY));
    }
    Point Point::moveTowards(Point source, Point other, double dist)
    {
        if (dist == 0)
            return Point(source.GetX(), source.GetY());
        if (dist < 0)
            throw invalid_argument("distance negative");
        double dis = source.distance(other);
        if(dis == 0) return Point(source.GetX(), source.GetY());
        if(dis <= dist) return Point(other.GetX(), other.GetY());
        double radi = dist / dis;
        double x = source.GetX() + (other.GetX() - source.GetX()) * radi;
        double y =  source.GetY() + (other.GetY() -  source.GetY()) * radi;
        return Point(x, y);
         }
    string Point::print()
    {
        return "(" + to_string(x_value) + ", " + to_string(y_value) + ")";
    }

}