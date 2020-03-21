#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;


BOOST_AUTO_TEST_SUITE( max_elevation_n0792831 )

const bool isFileName = true;
std::string dataDir = LogFiles::GPXRoutesDir + "/N0792831/";

BOOST_AUTO_TEST_CASE( oneValue )
{
    metres expectedData = 1000;

    Route trialRoute = Route(dataDir + "oneValue.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );


}

BOOST_AUTO_TEST_CASE( multipleValues )
{
    metres expectedData = 573;

    Route trialRoute = Route(dataDir + "multipleValues.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

BOOST_AUTO_TEST_CASE( largeAmountOfPositions )
{
    metres expectedData = 2500;

    Route trialRoute = Route(dataDir + "largeAmountOfPositions.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

BOOST_AUTO_TEST_CASE( duplicateElevation )
{
    metres expectedData = 573;

    Route trialRoute = Route(dataDir + "duplicateElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

BOOST_AUTO_TEST_CASE( duplicateMaxElevation )
{
    metres expectedData = 573;

    Route trialRoute = Route(dataDir + "duplicateMaxElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

BOOST_AUTO_TEST_CASE( extremeHigh )
{
    metres expectedData = 2147483647;

    Route trialRoute = Route(dataDir + "extremeHigh.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

BOOST_AUTO_TEST_CASE( elevation0 )
{
    metres expectedData = 0;

    Route trialRoute = Route(dataDir + "elevation0.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

BOOST_AUTO_TEST_CASE( negativeValue )
{
    metres expectedData = -500;

    Route trialRoute = Route(dataDir + "negativeValue.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

BOOST_AUTO_TEST_CASE( extremeNegative )
{
    metres expectedData = -2147483647;

    Route trialRoute = Route(dataDir + "extremeNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

BOOST_AUTO_TEST_CASE( mulitpleNegative )
{
    metres expectedData = -167;

    Route trialRoute = Route(dataDir + "multipleNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

//BOOST_AUTO_TEST_CASE( missingElevation )
//{
//    metres expectedData;

//    Route trialRoute = Route(dataDir + "missingElevation.gpx", isFileName);

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), std::invalid_argument );

//}

BOOST_AUTO_TEST_CASE( multipleValuesSomeMissing )
{
    metres expectedData = 573;

    Route trialRoute = Route(dataDir + "multipleValuesSomeMissing.gpx", isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), std::invalid_argument );

}




BOOST_AUTO_TEST_SUITE_END()

