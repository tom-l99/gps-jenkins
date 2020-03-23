#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( maxLatitude )

const bool isFileName = true;
std::string Data = LogFiles::GPXRoutesDir + "/N0798917/";


//Check that maxLatitude actually returns the max latitude of a typical route
BOOST_AUTO_TEST_CASE ( typical_route )
{
    degrees maxLat = 0.179964;
    Route route = Route(Data + "AHNT.gpx", isFileName);

    BOOST_CHECK_EQUAL(route.maxLatitude(), maxLat);
}


//Check that function works with a single point
BOOST_AUTO_TEST_CASE ( singlePoint )
{
    degrees maxLat = 0.089982;
    Route route = Route(Data + "singplePoint.gpx", isFileName);

    BOOST_CHECK_EQUAL(route.maxLatitude(), maxLat);
}


//Check that function works when Latitude = 0
BOOST_AUTO_TEST_CASE ( latitude_zero )
{
    Route route = Route(Data + "VRN.gpx", isFileName);

    BOOST_CHECK_EQUAL(route.maxLatitude(), 0);
}


//Check that function works with duplciate latitude values adn returnst he highest latitude
BOOST_AUTO_TEST_CASE ( duplicate_latitude )
{
    degrees maxLat = 0.179964;
    Route route = Route(Data + "duplicate.gpx", isFileName);

    BOOST_CHECK_EQUAL(route.maxLatitude(), maxLat);
}


//Check that function works with negative numbers and returns the lowest negative value
BOOST_AUTO_TEST_CASE ( negative_latitude )
{
    degrees maxLat = -0.089982;
    Route route = Route(Data + "VR.gpx", isFileName);

    BOOST_CHECK_EQUAL(route.maxLatitude(), maxLat);
}


//Check that function works with positive extreme value i.e Latitude = 90
BOOST_AUTO_TEST_CASE ( max_valid )
{
    degrees maxLat = 90;
    Route route = Route(Data + "positive_edge.gpx", isFileName);

    BOOST_CHECK_EQUAL (route.maxLatitude(), maxLat);
}


//Check that function works with negative extreme value i.e Latitude = -90
BOOST_AUTO_TEST_CASE ( min_valid )
{
    degrees maxLat = -90;
    Route route = Route(Data + "negative_edge.gpx", isFileName);

    BOOST_CHECK_EQUAL (route.maxLatitude(), maxLat);
}


//Check that function works with positive corner cases i.e Latitude = 89
BOOST_AUTO_TEST_CASE ( positive_corner )
{
    Route route = Route(Data + "positive_corner.gpx", isFileName);
    BOOST_CHECK_EQUAL (route.maxLatitude(), 89);
}


//Check that function works with negative corner cases i.e Latitude = -89
BOOST_AUTO_TEST_CASE ( negative_corner )
{
    Route route = Route(Data + "negative_corner.gpx", isFileName);
    BOOST_CHECK_EQUAL (route.maxLatitude(), -89);
}


//Function should throw an out of range error if latitude is beyond the range i.e outside -90 to 90
BOOST_AUTO_TEST_CASE ( above_max_valid )
{
    Route route = Route(Data + "max_boundary", isFileName);

    BOOST_CHECK_THROW (route.maxLatitude(), std::out_of_range);
}


BOOST_AUTO_TEST_SUITE_END( )
