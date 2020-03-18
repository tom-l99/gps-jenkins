#include<boost/test/unit_test.hpp>

#include <fstream>
#include "route.h"
#include "earth.h"

#include "gridworld/gridworld_route.h"

using namespace  GPS;

// Function to generate gpx files

const bool isFilename = true ;

std::string generate_file(std::string fileName, GridWorldRoute routeName) {
    std::string bringFileName = fileName + "/N0745071/"; // holds custom GPX data
    std::string holdsgpxdata = routeName.toGPX(true,fileName);
    std::ofstream gpxfile{logFiles::GPXRoutesDir + bringFileName}; gpxfile << holdsgpxdata ;
    gpxfile.close();
    return bringFileName;
 }


BOOST_AUTO_TEST_SUITE (Route_maxelevation_N0745071)

// Test Max Elevation with large data
BOOST_AUTO_TEST_CASE(max_elevation_large_data)
{
    Route path = Route(logFiles::GPXRoutesDir + "NorthYorkMoors.gpx", isFilename);
    BOOST_CHECK_EQUAL( path.maxElevation(), 505);
}

