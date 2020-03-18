#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE ( maxElevation_N0809215 )

const bool isFileName = false;
std::string gpxDat = LogFiles::GPXRoutesDir + "/N0809215/";

BOOST_AUTO_TEST_CASE( singleValue )
{
    metres Result = 700;

    Route routeData = Route(gpxDat + "singleValue.gpx", isFileName);

    BOOST_CHECK_EQUAL ( routeData.maxElevation(), Result);
}


BOOST_AUTO_TEST_CASE ( extremePositve )
{
    metres Result = 999999;

    Route routeData = Route(gpxDat + "extremePositive.gpx", isFileName);

    BOOST_CHECK_EQUAL ( routeData.maxElevation(), Result);
}


BOOST_AUTO_TEST_CASE ( extremeNegative )
{
    metres Result = -999999;

    Route routeData = Route(gpxDat + "extremeNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL ( routeData.maxElevation(), Result);
}

BOOST_AUTO_TEST_CASE ( multipleElevation )
{

    metres Result = 800;

    Route routeData = Route(gpxDat + "multipleElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL ( routeData.maxElevation(), Result);
}


BOOST_AUTO_TEST_CASE ( multipleMaxElevation )
{
    metres Result = 800;

    Route routeData = Route(gpxDat + "multipleMaxElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL ( routeData.maxElevation(), Result);
}

BOOST_AUTO_TEST_SUITE_END()
