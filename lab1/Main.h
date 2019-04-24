#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include "Haversine.h"
#include <sstream>
class Car
{
  private:
  public:
    float longtitude = 0.0;
    float latitude = 0.0;
    std::string CarName = "";
    std::string GpsLocationInfo()
    {
        std::ostringstream ss;
        ss << longtitude;
        std::string s(ss.str());
        std::ostringstream ss3;
        ss3 << latitude;
        std::string s2(ss3.str());
        return "Longitude: " + s + " Latitude: " + s2;
    }
    static Car *Create(std::string arg)
    {
        Car *tmp = new Car;
        tmp->CarName = arg;
        return tmp;
    }
    const Coordinate &UpdateLocation(float x, float y)
    {
        const Coordinate &tmp = *new Coordinate(x, y);
        longtitude = x;
        latitude = y;
        return tmp;
    }
};

class Distance
{
  private:
  public:
    float distance = 0.0;
    Distance(double a,double b,double c, double d)
    {
        float _distance=Haversine(a,b,c,d);
        distance=_distance;
    }
    Distance(Coordinate x, Coordinate y)
    {
        float _distance=Haversine(x.Longitude(),x.Latitude(),y.Longitude(),y.Latitude());
        distance=_distance;
    }
    float Value()const{return distance;}
};
#endif