#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( Route_minLongitude_N0786072 )

const bool isFileName = true; // All GPX data in this suite is provided as a file
std::string myDirectory = LogFiles::GPXRoutesDir + "N0786072/";

// Checks that it works even if only given a single value
BOOST_AUTO_TEST_CASE( longitude_SingleValue )
{
    Route route = Route( myDirectory + "longitudeSingleValue.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.118760108947754 );
}

// Checks that it correctly selects the right value when it is the first in the route
BOOST_AUTO_TEST_CASE( longitude_MinIsFirst )
{
    Route route = Route( myDirectory + "longitudeMinFirst.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}

// Checks that the last data point in the route is correctly extracted
BOOST_AUTO_TEST_CASE( longitude_MinIsLast )
{
    Route route = Route( myDirectory + "longitudeMinLast.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 108.934 );
}

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

// Checks that it can deal with numbers of very similar value
BOOST_AUTO_TEST_CASE( longitude_SimilarValues )
{
    Route route = Route( myDirectory + "longitudeSimilarValues.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 108.999999 );
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
