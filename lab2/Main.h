#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include "Haversine.h"
#include <sstream>
class Compass{
    public:
    virtual std::string CompassDirection(){
        return "C/West";
    }
    static std::string North(){
        return "North";
    }
};
class Gps: public virtual Compass{
    public:
    std::string str="";
    double x=0;
    double y=0;
    Gps(std::string _str,double _x, double _y)
    {
        str=_str;
        x=_x;
        y=_y;
    }
    Gps(){}
    std::string CompassDirection(){
        return "G/East";
    }
    Gps Location(){
        return *this;
    }
};
class TrackingSystem:public virtual Compass{
    public:
    std::string CompassDirection(){
        return "T/North";
    }
};
class TrackingUnit:public Gps,public TrackingSystem{
    public:
    Gps stashData;
    double startLatitude=0.0;
    double startLongitude=0.0;
    double currentLatitude=0.0;
    double currentLongitude=0.0;
    TrackingUnit(){}
    std::string CompassDirection(){
        return "TUnit/South";
    }
    void Start(){
        //std::cout << stashData.x << " "<< stashData.y<<std::endl;
        startLatitude=stashData.x;
        startLongitude=stashData.y;
    }
    void Location(Gps Arg)
    {
        stashData=Arg;
        currentLatitude=Arg.x;
        currentLongitude=Arg.y;
    }
    double Distance()
    {
        return Haversine(startLatitude,startLongitude,currentLatitude,currentLongitude);
    }
    std::string LocationInfo(){
        std::ostringstream ss;
        ss << currentLatitude;
        std::string s1(ss.str());
        std::ostringstream sss;
        sss << currentLongitude;
        std::string s2(sss.str());
        return "Longitude: "+s1+" Latitude: "+s2;
    }
    void Go(double x,std::string y){
       Coordinate tempObject(currentLatitude,currentLongitude);
       tempObject.MoveInDirection(x,y);
       currentLongitude=tempObject.Latitude();
       currentLatitude=tempObject.Longitude();
    }
};
#endif