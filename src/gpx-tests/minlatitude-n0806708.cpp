#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;
using namespace std;

BOOST_AUTO_TEST_SUITE (minLatitude_N0806708)

const bool isFileName = true;
string directory = LogFiles::GPXRoutesDir + "/N0806708/";

BOOST_AUTO_TEST_CASE (onePosition)
{
    Route testData = Route(directory + "onePosition.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.0179964);
}

BOOST_AUTO_TEST_CASE (zeroLatitude)
{
    Route testData = Route(directory + "zeroLatitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0);
}

BOOST_AUTO_TEST_CASE (typicalLatitudeInput)
{
    Route testData = Route(directory + "typicalLatitudeInput.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), -0.89982);
}

BOOST_AUTO_TEST_CASE (manyPositions)
{
    Route testData = Route(directory + "manyPositions.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), -1.79964);
}

BOOST_AUTO_TEST_CASE (duplicatePositions)
{
    Route testData = Route(directory + "duplicatePositions.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.89982);
}

BOOST_AUTO_TEST_CASE (negativeMinimumLatitude)
{
    Route testData = Route(directory + "negativeMinimumLatitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), -0.89982);
}

BOOST_AUTO_TEST_CASE (positiveMinimumLatitude)
{
    Route testData = Route(directory + "positiveMinimumLatitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.89982);
}

BOOST_AUTO_TEST_CASE (sameLatitudeDifferentLongitude)
{
    Route testData = Route(directory + "sameLatitudeDifferentLongitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.89982);
}

//BOOST_AUTO_TEST_CASE (closePositions)
//{

//}
//BOOST_AUTO_TEST_CASE (distantPositions)
//{

//}

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
