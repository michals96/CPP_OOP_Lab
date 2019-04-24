#ifndef H_COORDINATE_
#define H_COORDINATE_

#include <iostream> 
#include <cmath> 

////////////////////////////////////////////////////////////////////////
//
// distance between latitudes and longitudes returned in [km]
double Haversine(double lon1, double lat1, double lon2, double lat2);

////////////////////////////////////////////////////////////////////////
//
class PointedDistance {
  private:
    float m_distance;        // in [m]
    std::string m_direction; // South, North, East, West
  public:
    PointedDistance() = default;
    PointedDistance(float distance, std::string direction)
      : m_distance(distance),m_direction(direction){}
    ~PointedDistance() = default;  
    float Value() const {return m_distance;}
    std::string Direction() const {return m_direction;}
};

////////////////////////////////////////////////////////////////////////
//
class Coordinate {
  private:
    float m_longitude;
    float m_latitude;
  public:
    Coordinate() = default;   
    Coordinate(float longitude, float latitude)
      : m_longitude(longitude), m_latitude(latitude){}
    Coordinate(const Coordinate& coord){
        m_longitude = coord.Longitude();
        m_latitude = coord.Latitude();
    }  
    ~Coordinate() = default;

    float Latitude()const{return m_latitude;}
    float Longitude()const{return m_longitude;}
    void Latitude(float var){ m_latitude = var;}
    void Longitude(float var){ m_longitude = var;}

    // param xx_dinstance distance to go in meters
    // param direction one of fourth: "North", "South", "West", "East"
    void MoveInDirection(double xx_dinstance, std::string direction);

    Coordinate& operator += (const PointedDistance& pDistance){
        MoveInDirection(pDistance.Value(),pDistance.Direction());
        return *this;
    }
};

////////////////////////////////////////////////////////////////////////
//
class Distance {
  private:
    Coordinate m_start;
    Coordinate m_end;
  public:
    Distance() = default;

    Distance(const Coordinate& coord1, const Coordinate& coord2)
        : m_start(coord1),m_end(coord2){}

    Distance(float long1, float latt1, float long2, float latt2)
        :Distance(Coordinate(long1,latt1),Coordinate(long2,latt2)) {}

    ~Distance() = default;

    // Return actual distance value in [km]
    double Value() const {return Haversine(m_start.Longitude(),
                                    m_start.Latitude(),
                                    m_end.Longitude(),
                                    m_end.Latitude());}

    void Start(const Coordinate& start) {m_start = start;}
    
    void End(const Coordinate& end) {m_end = end;}
};

#endif // H_COORDINATE_