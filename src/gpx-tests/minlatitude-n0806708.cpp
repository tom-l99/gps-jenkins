#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE (Route_minLatitude_N0806708)

/* The minLatitude fucntion should return the minimum latitude value of the route
 * that has been specified by the user. Testing will need to be performed to ensure
 * the function performs as it should, with values being tested such as 0, negative
 * and positive minimum numbers, duplication of positions and boundary cases.
 *
 * Due to the nature of other functions it is not necessary to test this function with
 * erroneous values such as letters or latitude values that are out of the range -90 to
 * 90 and therefore invalid.
 */


const bool isFileName = true;
std::string directory = LogFiles::GPXRoutesDir + "/N0806708/";

// Test to prove that the function will return the minimum latitiude if only one position is entered
BOOST_AUTO_TEST_CASE (onePosition, * utf::tolerance(0.0001))
{
    Route testData = Route(directory + "onePosition.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.0179964);
}

// Test to prove that the function will return the minimum latitiude of 0 if it is required to so
BOOST_AUTO_TEST_CASE (zeroLatitude)
{
    Route testData = Route(directory + "zeroLatitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0);
}

// Test to prove that the function will return the minimum latitiude of the route even if there is duplicate values
BOOST_AUTO_TEST_CASE (duplicatePositions, * utf::tolerance(0.0001))
{
    Route testData = Route(directory + "duplicatePositions.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.89982);
}

// Test to prove that the function will return the minimum latitiude even if it returns a negative value
BOOST_AUTO_TEST_CASE (negativeMinimumLatitude, * utf::tolerance(0.0001))
{
    Route testData = Route(directory + "negativeMinimumLatitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), -0.89982);
}

// Test to prove that the function will return the minimum latitiude even if it returns a positive value
BOOST_AUTO_TEST_CASE (positiveMinimumLatitude, * utf::tolerance(0.0001))
{
    Route testData = Route(directory + "positiveMinimumLatitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.89982);
}

// Test to prove that the function will return the minimum latitiude of a typical route input
BOOST_AUTO_TEST_CASE (typicalLatitudeInput, * utf::tolerance(0.0001))
{
    Route testData = Route(directory + "typicalLatitudeInput.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), -0.89982);
}

// Test to prove that the function will return the minimum latitiude if a large dataset is entered
BOOST_AUTO_TEST_CASE (manyPositions, * utf::tolerance(0.0001))
{
    Route testData = Route(directory + "manyPositions.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), -1.79964);
}

// Test to prove that the function will return the minimum latitiude even if the longitudes are different
BOOST_AUTO_TEST_CASE (sameLatitudeDifferentLongitude, * utf::tolerance(0.0001))
{
    Route testData = Route(directory + "sameLatitudeDifferentLongitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.89982);
}

// Test to prove that the function will return the minimum latitiude to at least 6 decimal places
BOOST_AUTO_TEST_CASE (closePositions, * utf::tolerance(0.0001))
{
    Route testData = Route(directory + "closePositions.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.898471);
}
// Tests to prove that the function will return the minimum latitude for boundary cases
BOOST_AUTO_TEST_CASE (latitudeBorderLow)
{
    Route testData = Route(directory + "latitudeBorderLow.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), -90);
}

BOOST_AUTO_TEST_CASE (latitudeBorderHigh)
{
    Route testData = Route(directory + "latitudeBorderHigh.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 90);
}

BOOST_AUTO_TEST_SUITE_END()
