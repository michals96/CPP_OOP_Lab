#include "Main.h"
#include "Haversine.h"
#include <sstream>

int main(){

	Car* mercedes = Car::Create("Mercedes");
	Car* ford = Car::Create("Ford");

	// Update location parameters stored in GPS Coordinate instance:
	Coordinate MercCoordinate ( mercedes->UpdateLocation(19.9449799,50.0646501) ); 	  // Longitude, Latitude; Krakow :)
	Coordinate FordCoordinate ( ford->UpdateLocation(21.012229,52.229676) );		  // Longitude, Latitude; Warszawa;
	MercCoordinate+=PointedDistance(2,"South"); // move 2 meters into South;
	MercCoordinate+=PointedDistance(5,"West"); 	// move 5 meters into West;
	FordCoordinate+=PointedDistance(1,"North"); // move 1 meters into South;
	FordCoordinate+=PointedDistance(3,"East"); 	// move 1 meters into East;

	Distance distanceBetweenCars(MercCoordinate,FordCoordinate);
	std::cout<<"[INFO]:: Mercedes location " << mercedes->GpsLocationInfo()<<"\n";
	std::cout<<"[INFO]:: Ford location     " << ford->GpsLocationInfo()<<"\n";
	std::cout<<"[INFO]:: M-F distance      " << distanceBetweenCars.Value() << " [km]\n";

	//simple check:
	Distance distance(MercCoordinate.Longitude(),
						 MercCoordinate.Latitude(),
						 FordCoordinate.Longitude(),
						 FordCoordinate.Latitude());

	std::cout<<"[INFO]:: Distance check    " << distance.Value() << " [km]" <<std::endl;

	delete mercedes;
	delete ford;

	return 0;
}
