#include <iostream>
#include <fstream>
#include <cassert>

#include "gridworld_model.h"
#include "gridworld_route.h"
#include "gridworld_track.h"

using namespace GPS;

int main()
{
    //std::string exampleRouteString = "ABC";
    //assert( GridWorldRoute::isValidRouteString(exampleRouteString) );
    //GridWorldRoute exampleGWroute(exampleRouteString);
    //std::cout << exampleGWroute.toGPX() << std::endl;


    // square distance metres and height
    GridWorldModel Grid_unit_distance = GPS::GridWorldModel(Earth::EquatorialMeridian, 1000, 5);
    
    std::string exampleRouteString = "M";
    
    assert( GridWorldRoute::isValidRouteString(exampleRouteString) );   
    
    //GridWorldRoute exampleGWroute(exampleRouteString);
    
    GridWorldRoute points = GridWorldRoute(exampleRouteString,Grid_unit_distance);
    
    std::cout << points.toGPX() << std::endl;
    
    std::ofstream myfile("/home/n0806708/gps/logs/GPX/routes/N0806708/zeroLatitude.gpx");
    
    myfile << points.toGPX() << std::endl;
    myfile.close();
    return 0;
}
