#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE ( maxElevation_N0809215 )

const bool isFileName = true;
std::string gpxDat = LogFiles::GPXRoutesDir + "/N0809215/";

BOOST_AUTO_TEST_CASE( singleValue )
{
    metres Result = 700;

    Route routeData = Route(gpxDat + "singleValue.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result) ;
}


BOOST_AUTO_TEST_CASE( multipleValues )
{
    metres Result = 700;

    Route routeData = Route(gpxDat + "multipleValues.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result) ;
}


BOOST_AUTO_TEST_CASE( extremePositve )
{
    metres Result = 99999;

    Route routeData = Route(gpxDat + "extremePositive.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}


BOOST_AUTO_TEST_CASE( extremeNegative )
{
    metres Result = -99999;

    Route routeData = Route(gpxDat + "extremeNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}


BOOST_AUTO_TEST_CASE( positiveNatExtreme )
{
    metres Result = 8848;

    Route routeData = Route(gpxDat + "positiveNatExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}


BOOST_AUTO_TEST_CASE( negativeNatExtreme )
{
    metres Result = -10916;

    Route routeData = Route(gpxDat + "positiveNatExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}


BOOST_AUTO_TEST_CASE( positiveElevationExtreme )
{
    metres Result = 1.79769e+308;

    Route routeData = Route(gpxDat + "positiveElevationExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}


BOOST_AUTO_TEST_CASE( negativeElevationExtreme )
{
    metres Result = -1.79769e+308;

    Route routeData = Route(gpxDat + "negativeElevationExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}

BOOST_AUTO_TEST_SUITE_END()
