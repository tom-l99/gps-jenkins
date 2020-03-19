#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( maxLatitude )

const bool isFileName = false;
std::string Data = LogFiles::GPXRoutesDir + "/N0798917/";


//Check that maxLatitude actually returns the max latitude of a typical route
BOOST_AUTO_TEST_CASE ( typical_route )
{
    degrees maxLat = 0.179964;
    Route route = Route(Data + "AHNT.gpx", true);

    BOOST_CHECK_EQUAL(Route.maxLatitude(), maxLat);
}


//Check that function works with negative numbers and returns the lowest negative value
BOOST_AUTO_TEST_CASE ( negative_latitude )
{
    degrees maxLat = -0.089982;
    Route route = Route(Data + "VR.gpx", true);

    BOOST_CHECK_EQUAL(Route.maxLatitude(), maxLat);
}


//Check that function works when Latitude = 0
BOOST_AUTO_TEST_CASE ( latitude_zero )
{
    Route route = Route(Data + "VRN.gpx", true);

    BOOST_CHECK_EQUAL(Route.maxLatitude(), 0);
}


//Check that function works with positive extreme value i.e Latitude = 90
BOOST_AUTO_TEST_CASE ( max_valid )
{
    degrees maxLat = 90;
    Route route = Route(Data + "positive_edge.gpx", true);

    BOOST_CHECK_EQUAL (Route.maxLatitude(), maxLat);
}


//Check that function works with negative extreme value i.e Latitude = -90
BOOST_AUTO_TEST_CASE ( min_valid )
{
    degrees maxLat = -90;
    Route route = Route(Data + "negative_edge.gpx", true);

    BOOST_CHECK_EQUAL (Route.maxLatitude(), maxLat);
}


//Function should throw an out of range error if latitude is beyond the range i.e outside -90 to 90
BOOST_AUTO_TEST_CASE ( above_max_valid )
{
    Route route = Route(Data + "max_boundary", true);

    BOOST_CHECK_THROW (Route.maxLatitude(), std::out_of_range)
}



BOOST_AUTO_TEST_SUITE_END( )
