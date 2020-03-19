#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;

//BOOST Description
//This is the description of the test suite and the declartion for the log file which i have containing the GPX datas
BOOST_AUTO_TEST_SUITE ( maxElevation_N0809215 )

const bool isFileName = true;
std::string gpxDat = LogFiles::GPXRoutesDir + "/N0809215/";

//BOOST Test Cases

//Typcial Inputs
//This test is designed to search through the GPX data and pick out a single value
BOOST_AUTO_TEST_CASE( singleValue )
{
    metres Result = 700;

    Route routeData = Route(gpxDat + "singleValue.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result);
}

//This test is designed to search through the GPX data and pick out a single value from a file where there multiple values inputted
BOOST_AUTO_TEST_CASE( multipleValues )
{
    metres Result = 700;

    Route routeData = Route(gpxDat + "multipleValues.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result);
}

//Error Case
//This test is designed to look in the GPX data for the Result number but it is incorrect in the GPX data, so this should throw an error
BOOST_AUTO_TEST_CASE( incorrectElevation )
{
    metres Result = 400;

    Route routeData = Route(gpxDat + "incorrectElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result) ;
}

//Boundary Cases
//This test is designed to find the extreme positive that the elevation can be
BOOST_AUTO_TEST_CASE( extremePositve )
{
    metres Result = 99999;

    Route routeData = Route(gpxDat + "extremePositive.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}

//This test is designed to find the extreme negative that the elevation can be
BOOST_AUTO_TEST_CASE( extremeNegative )
{
    metres Result = -99999;

    Route routeData = Route(gpxDat + "extremeNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}

//This test is designed to find the extreme real-world positive that the elevation can be
BOOST_AUTO_TEST_CASE( positiveNatExtreme )
{
    metres Result = 8848;

    Route routeData = Route(gpxDat + "positiveNatExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}

//This test is designed to find the extreme real-world negative that the elevation can be
BOOST_AUTO_TEST_CASE( negativeNatExtreme )
{
    metres Result = -10916;

    Route routeData = Route(gpxDat + "positiveNatExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}

//Edge Cases
//This test is designed to test the absolute maximum that a positive double number can be
BOOST_AUTO_TEST_CASE( positiveElevationExtreme )
{
    metres Result = 1.79769e+308;

    Route routeData = Route(gpxDat + "positiveElevationExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}

//This test is designed to test the absolute maximum that a negative double number can be
BOOST_AUTO_TEST_CASE( negativeElevationExtreme )
{
    metres Result = -1.79769e+308;

    Route routeData = Route(gpxDat + "negativeElevationExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}

//Corner Cases
//This test is designed to test the overflow positive of the double variable
BOOST_AUTO_TEST_CASE( overflowPositive )
{
    metres Result = -1.79769e+309;

    Route routeData = Route(gpxDat + "overflowPositivegpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}

//This test is designed to test the overflow negative of the double variable
BOOST_AUTO_TEST_CASE( overflowNegative )
{
    metres Result = -1.79769e+309;

    Route routeData = Route(gpxDat + "overflowNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.maxElevation(), Result );
}


BOOST_AUTO_TEST_SUITE_END()
