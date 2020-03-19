#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE minLongitude_N0786072

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( Route_minLongitude_N0786072 )

const bool isFileName = true; // All GPX data in this suite is provided as a file
std::string myDirectory = LogFiles::GPXRoutesDir + "N0786072/";

// Empty
BOOST_AUTO_TEST_CASE( longitude_Empty )
{
    Route route = Route( myDirectory + "longitudeEmpty.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}

// Blank
BOOST_AUTO_TEST_CASE( longitude_Blank )
{
    Route route = Route( myDirectory + "longitudeBlank.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}

// Missing
BOOST_AUTO_TEST_CASE( longitude_Missing )
{
    Route route = Route( myDirectory + "longitudeMissing.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}

// Is an integer
BOOST_AUTO_TEST_CASE( longitude_Integer )
{
    Route route = Route(myDirectory + "longitudeInteger.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.minLongitude(), 108 );
}

// Is a float
BOOST_AUTO_TEST_CASE( longitude_Float )
{
    Route route = Route( myDirectory + "longitudeFloat.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.42 );
}

// Extremely small
BOOST_AUTO_TEST_CASE( longitude_Small )
{
    Route route = Route( myDirectory + "longitudeSmall.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 0.000000000000001 );
}

// Extreme positive
BOOST_AUTO_TEST_CASE( longitude_LargePos )
{
    Route route = Route( myDirectory + "longitudeLargePos.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.42 );
}

// Extreme negative
BOOST_AUTO_TEST_CASE( longitude_LargeNeg )
{
    Route route = Route( myDirectory + "longitudeLargeNeg.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -180.000 );
}

// Is 0
BOOST_AUTO_TEST_CASE( longitude_IsZero )
{
    Route route = Route( myDirectory + "longitudeIsZero.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 0 );
}

// Negative 0
BOOST_AUTO_TEST_CASE( longitude_NegZero )
{
    Route route = Route( myDirectory + "longitudeNegZero.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 0 );
}

// 2 Repeated values
BOOST_AUTO_TEST_CASE( longitude_RepeatedSmallest )
{
    Route route = Route( myDirectory + "longitudeSmallestRepeated.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.42 );
}

// Small typical file
BOOST_AUTO_TEST_CASE( longitude_SmallActualFile )
{
    Route route = Route( myDirectory + "smallActualRoute.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.118760108947754 );
}

// Large typical file
BOOST_AUTO_TEST_CASE( longitude_LargeActualFile )
{
    Route route = Route( myDirectory + "largeActualRoute.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.120702028274536 );
}

BOOST_AUTO_TEST_SUITE_END()
