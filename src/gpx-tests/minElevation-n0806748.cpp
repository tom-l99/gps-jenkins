#include <boost/test/unit_test.hpp>

#include "route.h"
#include "logs.h"
#include "types.h"

// Boost - Setting up the boost auto test name
BOOST_AUTO_TEST_SUITE(minElevation_N0806748)

// First string is to have a easy way to have the directory to the logs folder
// Second is checking if the file exists
const std::string fileDir = GPS::LogFiles::GPXRoutesDir + "N0806748/";
const bool isFileName = true;

// TYPCIAL INPUT CASE TESTS
// These tests are designed to search through the inputted GPX data and try to pick out the minimal single value
BOOST_AUTO_TEST_CASE( singleValue )
{
    const GPS::metres result = 100;

    GPS::Route routeData = GPS::Route(fileDir + "singleValue.gpx", isFileName);
    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

BOOST_AUTO_TEST_CASE( multipleValues_Default )
{
    const GPS::metres result = 0;

    GPS::Route routeData = GPS::Route(fileDir + "multipleValues_Default.gpx", isFileName);
    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

BOOST_AUTO_TEST_CASE( multipleValues_AGMSY )
{
    const GPS::metres result = -5;

    GPS::Route routeData = GPS::Route(fileDir + "multipleValues_AGMSY.gpx", isFileName);
    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// ERROR CASE TESTS
// Looks at GPX data for result but has incorrect GPX data throwing an error
BOOST_AUTO_TEST_CASE( incorrectElevation )
{
    const GPS::metres Result = 500;

    GPS::Route routeData = GPS::Route(fileDir + "singleInvalidElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result) ;
}

// Checks GPX file for no elevation inputted
BOOST_AUTO_TEST_CASE( blankElevation )
{
    const GPS::metres result = NULL;

    GPS::Route routeData = GPS::Route(fileDir + "blankElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), result) ;
}

// BOUNDARY CASE TESTS
// Test to find the extreme positive elevation
BOOST_AUTO_TEST_CASE( extremePositve )
{
    const GPS::metres result = 999999;

    GPS::Route routeData = GPS::Route(fileDir + "singleExtremePositive.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// Test to find the extreme negative elevation
BOOST_AUTO_TEST_CASE( extremeNegative )
{
    const GPS::metres result = -999999;

    GPS::Route routeData = GPS::Route(fileDir + "singleExtremeNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// Test to find the extreme real world data of positive elevation
// NEED TO FIX DATA
BOOST_AUTO_TEST_CASE( positiveNatExtreme )
{
    const GPS::metres result = 8850;

    GPS::Route routeData = GPS::Route(fileDir + "realWorldPositive.gpx", isFileName);
    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// Test to find the extreme real world data of negative elevation
// NEED TO FIX DATA
BOOST_AUTO_TEST_CASE( negativeNatExtreme )
{
    const GPS::metres result = -413;

    GPS::Route routeData = GPS::Route(fileDir + "positiveNatExtreme.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// EDGE CASE TESTS
// Test to find the absolute maximum postive double number
BOOST_AUTO_TEST_CASE( positiveElevationExtreme )
{
    const GPS::metres result = 1.79769e+308;

    GPS::Route routeData = GPS::Route(fileDir + "positiveElevationExtreme.gpx", isFileName);
    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// Test to find the absolute maximum negative double number

BOOST_AUTO_TEST_CASE( negativeElevationExtreme )
{
    const GPS::metres result = -1.79769e+308;

    GPS::Route routeData = GPS::Route(fileDir + "negativeElevationExtreme.gpx", isFileName);
    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// CORNER CASE TESTS
// Test overflow positive of the double variable | DOCUMENT OUTPUT IF INF NOT A NUMBER
BOOST_AUTO_TEST_CASE( overflowPositive )
{
    const GPS::metres result = 1.79769e+309;

    GPS::Route routeData = GPS::Route(fileDir + "positiveOverflow.gpx", isFileName);
    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// Test overflow negative of the double variable

BOOST_AUTO_TEST_CASE( overflowNegative )
{
    const GPS::metres result = -1.79769e+309;

    GPS::Route routeData = GPS::Route(fileDir + "negativeOverflow.gpx", isFileName);
    BOOST_CHECK_EQUAL( routeData.minElevation(), result );
}

// To-Do LIST
// ----------
// Add Mutiple varibles of inputs
// Check over data and expected results
// Jenkins on own server
// Write document

BOOST_AUTO_TEST_SUITE_END()
