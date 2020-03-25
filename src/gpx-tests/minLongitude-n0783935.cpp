#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( MinimumLongitudeN0783935 )

const bool isFileName = true;
std::string dataDirectory = LogFiles::GPXRoutesDir + "/N0783935/";

// Tests whether the expected minimum longitude value is returned
// when there is only one value within the route
BOOST_AUTO_TEST_CASE( singuleInput )
{
    Route route = Route( dataDirectory + "singleInput.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -0.898312 );
}

// Tests whether the expected minimum longitude value is returned
// when the minimum value is zero
BOOST_AUTO_TEST_CASE( zero )
{
    Route route = Route( dataDirectory + "zero.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 0 );
}

// Tests whether the expected minimum longitude value is returned
// when the minimum edge is an integer
BOOST_AUTO_TEST_CASE( minimumIntegerEdgeCase )
{
    Route route = Route( dataDirectory + "minimumIntegerEdgeCase.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -180 );
}

// Tests whether the expected minimum longitude value is returned
// when the minimum edge is a decimal
BOOST_AUTO_TEST_CASE( minimumDecimalEdgeCase )
{
    Route route = Route( dataDirectory + "minimumDecimalEdgeCase.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -180.00 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset only consists of positive integers
BOOST_AUTO_TEST_CASE( positiveInteger )
{
    Route route = Route( dataDirectory + "positiveIntegers.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 12 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset only consists of negative integers
BOOST_AUTO_TEST_CASE( negativeInteger )
{
    Route route = Route( dataDirectory + "negativeIntegers.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -168 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset only consists of positive decimals
BOOST_AUTO_TEST_CASE( positiveDecimal )
{
    Route route = Route( dataDirectory + "positiveDecimals.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), 109.142 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset only consists of negative decimals
BOOST_AUTO_TEST_CASE( negativeDecimal)
{
    Route route = Route( dataDirectory + "negativeDecimals.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -109.412 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset consists of long decimals
BOOST_AUTO_TEST_CASE( longDecimals )
{
    Route route = Route( dataDirectory + "longDecimals.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -109.41212994752894658 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset consist of values of low variance
BOOST_AUTO_TEST_CASE( closeDecimalDifference )
{
    Route route = Route( dataDirectory + "closeDecimalDifference.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -109.322194653874 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset consists of both positive and negative integers
BOOST_AUTO_TEST_CASE( positiveNegativeIntegers )
{
    Route route = Route( dataDirectory + "positiveNegativeIntegers.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -152 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset consists of both positive and negative decimals
BOOST_AUTO_TEST_CASE( positiveNegativeDecimals )
{
    Route route = Route( dataDirectory + "positiveNegativeDecimals.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -72.79458 );
}

// Tests whether the expected minimum longitude value is returned
// when the dataset consists of both positive and negative decimals and integers
BOOST_AUTO_TEST_CASE( decimalsIntegers )
{
    Route route = Route( dataDirectory + "decimalsIntegers.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -164.54986 );
}

// Tests whether the expected minimum longitude value is returned in a small route
BOOST_AUTO_TEST_CASE( smallRoute )
{
    Route route = Route( dataDirectory + "smallRoute.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.099292635917664 );
}

// Tests whether the expected minimum longitude value is returned in a medium route
BOOST_AUTO_TEST_CASE( mediumRoute )
{
    Route route = Route( dataDirectory + "mediumRoute.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.096229553222657 );
}

// Tests whether the expected minimum longitude value is returned in a large route
BOOST_AUTO_TEST_CASE( largeRoute )
{
    Route route = Route( dataDirectory + "largeRoute.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.066730618476867 );
}

// Tests whether the expected minimum longitude value is returned
// when it is the first value in the dataset
BOOST_AUTO_TEST_CASE( firstMinimum )
{
    Route route = Route( dataDirectory + "firstMinimum.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.067057847976685 );
}

// Tests whether the expected minimum longitude value is returned
// when it is the last value in the dataset
BOOST_AUTO_TEST_CASE( lastMinimum )
{
    Route route = Route( dataDirectory + "lastMinimum.gpx", isFileName );
    BOOST_CHECK_EQUAL( route.minLongitude(), -1.066548265875843 );
}

BOOST_AUTO_TEST_SUITE_END()
