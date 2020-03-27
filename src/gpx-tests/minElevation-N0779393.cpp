#include <boost/test/unit_test.hpp>

#include "route.h"
#include "logs.h"
#include "types.h"

using namespace GPS;

// BOOST test name
BOOST_AUTO_TEST_SUITE(minElevation_N0779393)

const bool isFileName = true; // All GPX data in suite loaded from files
const std::string gpxDir = "/N0779393/"; // load GPX data from this folder

// ==Typical input tests==
// Aimed to search through GPX data and attempt to find min single value

BOOST_AUTO_TEST_CASE( multipleVals_DEFAULT )
{
	const GPS::metres Result = 0;

	GPS::Route rData = GPS::Route(gpxDir + "multipleVals_DEFAULT.gpx", isFileName);

	BOOST_CHECK_EQUAL( rData.minElevation(), Result );	
}

// Test that single positive value is handled
BOOST_AUTO_TEST_CASE( singlepositiveVal )
{
    const GPS::metres Result = 200;

    GPS::Route rData = GPS::Route(gpxDir + "singlepositiveVal.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}

// Test that single negative value is handled
BOOST_AUTO_TEST_CASE( singlenegativeVal )
{
    const GPS::metres Result = -200;

    GPS::Route rData = GPS::Route(gpxDir + "singlenegativeVal.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}

// Test that the lowest positive number out of multiple handled values is returned
BOOST_AUTO_TEST_CASE( multiplepositiveVal )
{
    const GPS::metres Result = 100;

    GPS::Route rData = GPS::Route(gpxDir + "multiplepositiveVal.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}

// Test that the lowest negative number out of multiple handled values is returned
BOOST_AUTO_TEST_CASE( multiplenegativeVal )
{
    const GPS::metres Result = -100;

    GPS::Route rData = GPS::Route(gpxDir + "multiplenegativeVal.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}

// Test that decimals are handled
BOOST_AUTO_TEST_CASE( decimalVal )
{
    const GPS::metres Result = 175.75;

    GPS::Route rData = GPS::Route(gpxDir + "decimalVal.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}

// Test that values are rounded to 2 d.p
BOOST_AUTO_TEST_CASE( roundingVal )
{
    const GPS::metres Result = 150.09;

    GPS::Route rData = GPS::Route(gpxDir + "roundingVal.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}


// ==Typical error tests==
// Check for incorrect GPX errors

// Test for GPX file having no elevation input
BOOST_AUTO_TEST_CASE( emptyElevation )
{
    const GPS::metres Result = std::domain_error

    GPS::Route rData = GPS::Route(gpxDir + "emptyElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result ) ;
}

// Checks for invalid GPX data throwing error
BOOST_AUTO_TEST_CASE( wrongElevation )
{
    const GPS::metres Result = 502;

    GPS::Route rData = GPS::Route(gpxDir + "wrongElevation.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result ) ;
}

// ==Boundary tests==
// Check lowest handled C++ double value
BOOST_AUTO_TEST_CASE( extremeNegative )
{
	const GPS::metres Result = -1.79769e+308;

    GPS::Route rData = GPS::Route(gpxDir + "extremeNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}

// Check highest handled C++ double value
BOOST_AUTO_TEST_CASE( extremePositive )
{
	const GPS::metres Result = 1.79769e+308;

    GPS::Route rData = GPS::Route(gpxDir + "extremePositive.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}

// ==Overflow tests==
// Test overflow for a positive double
BOOST_AUTO_TEST_CASE( overflowPositive )
{
    const GPS::metres Result = 1.79769e+309;

    GPS::Route rData = GPS::Route(fileDir + "overflowPositive.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}

// Test overflow for a negative double
BOOST_AUTO_TEST_CASE( overflowNegative )
{
    const GPS::metres Result = -1.79769e+309;

    GPS::Route rData = GPS::Route(fileDir + "overflowNegative.gpx", isFileName);

    BOOST_CHECK_EQUAL( routeData.minElevation(), Result );
}


BOOST_AUTO_TEST_SUITE_END()
