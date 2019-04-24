#include "Main.h"

int main(){

	Compass myCompass;
	TrackingSystem myTrackingSystem;
	TrackingUnit myTrackingUnit;
	Gps myGps("Garmin",19.9449799,50.0646501);

	std::cout<<"[INFO]:: **** Inheritance behavior ****" << "\n";

	std::cout<<"[INFO]:: Direction from compass instance:         "
		<< myCompass.CompassDirection()<<"\n";
	
	std::cout<<"[INFO]:: Direction from tracking system instance: "
		<< myTrackingSystem.CompassDirection()<<"\n";
	
	std::cout<<"[INFO]:: Direction from tracking unit instance:   "
		<< myTrackingUnit.CompassDirection()<<"\n";
	
	std::cout<<"[INFO]:: Direction from gps instance:             "
		<< myGps.CompassDirection()<<"\n";

	std::cout<<"[INFO]:: **** Actual lab07 problem ****" << "\n";

	myTrackingUnit.Location(myGps.Location());
	
	myTrackingUnit.Start(); // set current Gps location as a starting point
	
	std::cout<<"[INFO]:: Distance before Go: "
		<< myTrackingUnit.Distance() << " [km]"<< "\n";	

	std::cout<<"[INFO]:: Start position: "
		<< myTrackingUnit.LocationInfo() << "\n";

	myTrackingUnit.Go(2000,Compass::North());
	
	std::cout<<"[INFO]:: End position:   "
		<< myTrackingUnit.LocationInfo() << "\n";

	std::cout<<"[INFO]:: Distance after Go: "
		<< myTrackingUnit.Distance() << " [km]"<< "\n";	
	return 0;
}

