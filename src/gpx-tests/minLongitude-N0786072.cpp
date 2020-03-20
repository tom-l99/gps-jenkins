#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE minLongitude_N0786072

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( Route_minLongitude_N0786072 )

/* Route.minLongitude() should return the minimum value for the longitude from a given Route,
 * which is taken from the content of the ' <rtept> lon="" ' element (within the <rte> element)
 * in the GPX data that the Route was made from.
 *
 * The main point for testing is to ascertain if the function is able to correctly identify
 * the longitude values from the route, and then store and return which one is the smallest - or
 * the most Western point of data.
 *
 * The tests start by checking that the function works with a relatively small typical file
 * consisting of 15 points of real-world data.
 *
 * The tests then move onto using a full route using real-world data that consists of roughly
 * 1000 points of data.
 *
 * The next couple of tests are to check that it can handle differing types of data such as
 * the string making up an integer or a float, as well as how it handles extreme values
 * (within -180 and 180.)
 *
 * Finally the tests then check to see how the function handles repeated values.
*/

const bool isFileName = true; // All GPX data in this suite is provided as a file
std::string myDirectory = LogFiles::GPXRoutesDir + "N0786072/";

// Checks that it can correctly extract the minimum longitude from a small data set
BOOST_AUTO_TEST_CASE( longitude_SmallActualFile )
{
    Route route = Route( myDirectory + "smallActualRoute.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.118760108947754 );
}

// Checks that it can correctly extract the minimum longitude from a large data set
BOOST_AUTO_TEST_CASE( longitude_LargeActualFile )
{
    Route route = Route( myDirectory + "largeActualRoute.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.120702028274536 );
}

// Checks that the function can cope when the value given is just an integer string
BOOST_AUTO_TEST_CASE( longitude_Integer )
{
    Route route = Route(myDirectory + "longitudeInteger.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.minLongitude(), 108 );
}

// Checks that it doesn't lose precision when handling a very small decimal
BOOST_AUTO_TEST_CASE( longitude_Small )
{
    Route route = Route( myDirectory + "longitudeSmall.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 0.000000000000001 );
}

// Checks that it can still retrieve the correct value even when other points are at the maximum accepted
BOOST_AUTO_TEST_CASE( longitude_LargePos )
{
    Route route = Route( myDirectory + "longitudeLargePos.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}

// Checks that it can still retrieve the correct value even when other points are at the minimum accepted
BOOST_AUTO_TEST_CASE( longitude_LargeNeg )
{
    Route route = Route( myDirectory + "longitudeLargeNeg.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -180.000 );
}

// Checks that it can retrieve the correct minimum longitude when it is 0
BOOST_AUTO_TEST_CASE( longitude_IsZero )
{
    Route route = Route( myDirectory + "longitudeIsZero.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 0 );
}

// Checks that it can retrieve the correct minimum longitude even when it is given -0
BOOST_AUTO_TEST_CASE( longitude_NegZero )
{
    Route route = Route( myDirectory + "longitudeNegZero.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 0 );
}

// Checks that it can handle repeated instances of the desired value
BOOST_AUTO_TEST_CASE( longitude_RepeatedSmallest )
{
    Route route = Route( myDirectory + "longitudeSmallestRepeated.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}

// Checks that it can still retrieve the correct value even if other data points are repeated
BOOST_AUTO_TEST_CASE( longitude_RepeatedOthers )
{
    Route route = Route( myDirectory + "longitudeRepeatedOthers.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}

// Combines the previous two tests
BOOST_AUTO_TEST_CASE( longitude_RepeatedSmallestAndOthers )
{
    Route route = Route( myDirectory + "longitudeRepeatedAll.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}


BOOST_AUTO_TEST_SUITE_END()
