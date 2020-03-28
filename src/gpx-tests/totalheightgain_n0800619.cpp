#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE(totalHeightGain_N0800619)

const metres defaulTotalHeightGain = 0.00000;

const metres percentageAccuracy = 0.00001;

std::string gpxData = LogFiles::GPXRoutesDir + "/N0800619/";
const bool isFileName = true; // All GPX data in this suite is provided from files.

//Typical values for elevation for which the total height gain changes value
BOOST_AUTO_TEST_CASE(normalElevationValues)
{
    const metres expectedValue = 0.00000;
    Route route = Route(gpxData + "ABCD.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), expectedValue, percentageAccuracy );
}

//Typical values for elevation for which the total height gain changes value
BOOST_AUTO_TEST_CASE(normalElevationValuesDifferentFromZero)
{
    const metres expectedValue = 20000.00000;
    Route route = Route(gpxData + "ABQWE.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), expectedValue, percentageAccuracy );
}

//Check if total height gain is 0 if all the height differences are negative
BOOST_AUTO_TEST_CASE(negativeElevationGivesNegativeDifferenceBetweenPoints)
{
    Route route = Route(gpxData + "negDiffSumZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalHeightGain(), defaulTotalHeightGain);
}

//Check if total height gain is 0 if single elevation value in file
BOOST_AUTO_TEST_CASE(oneValue)
{
    Route route = Route(gpxData + "Q.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), defaulTotalHeightGain, percentageAccuracy);
}

//Check if total height gain changes value even for extremly low height differences
BOOST_AUTO_TEST_CASE(valueJustAbovePercentageAccuracy)
{
    const metres expectedValue = 0.00010;
    Route route = Route(gpxData + "ABQ.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), expectedValue, percentageAccuracy);
}

//Total height gain is zero if the elevation field is blank - doesn't contain a value but a space
BOOST_AUTO_TEST_CASE(blankElevationField)
{
    Route route = Route(gpxData + "blankElevationField.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalHeightGain(), defaulTotalHeightGain);
}

//Total height gain is zero if the elevation field is empty - doesn't contain a value
BOOST_AUTO_TEST_CASE(emptyElevationField)
{
    Route route = Route(gpxData + "noElevationValue.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalHeightGain(), defaulTotalHeightGain);
}

//No elevation field throws an exception
BOOST_AUTO_TEST_CASE(noElevationField)
{
    Route route = Route(gpxData + "noElevationField.gpx", isFileName);
    BOOST_CHECK_THROW(route.totalHeightGain(), std :: invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
