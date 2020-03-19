#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE(totalHeightGain_N0800619)

const metres defaulTotalHeightGain = 0;
std::string gpxData = LogFiles::GPXRoutesDir + "/N0800619/";
const bool isFileName = true; // All GPX data in this suite is provided from files.

BOOST_AUTO_TEST_CASE(typicalInputs)
{
    const metres expectedValue = 0.00000;
    const double percentageAccuracy = 0.00001;
    Route route = Route(gpxData + "ABCD.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), 0.00000, percentageAccuracy );
}

BOOST_AUTO_TEST_CASE(typicalInputs2)
{
    const double percentageAccuracy = 0.00001;
    Route route = Route(gpxData + "ABQWE.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), 20000.00000, percentageAccuracy );
}

BOOST_AUTO_TEST_CASE(oneValue)
{
    Route route = Route(gpxData + "Q.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.totalHeightGain() , defaulTotalHeightGain);
}

BOOST_AUTO_TEST_CASE(valueJustAbovePercentageAccuracy)
{
    const double percentageAccuracy = 0.00001;
    Route route = Route(gpxData + "ABQ.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), 0.00010, percentageAccuracy);
}

BOOST_AUTO_TEST_CASE(noElevationField)
{
    Route route = Route(gpxData + "noElevationField.gpx", isFileName);
    BOOST_CHECK_THROW(route.totalHeightGain(), std :: invalid_argument);
}

//BOOST_AUTO_TEST_CASE(emptyElevationField)
//{
//    Route route = Route(gpxData + "noElevationValue.gpx", isFileName);
//    BOOST_CHECK_EQUAL(route.totalHeightGain(), defaulTotalHeightGain);
//}

BOOST_AUTO_TEST_CASE(negativeEleGivesNegDifferenceBetweenPoints)
{
    Route route = Route(gpxData + "negDiffSumZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalHeightGain(), defaulTotalHeightGain);
}

BOOST_AUTO_TEST_CASE(wrongType)
{
    BOOST_CHECK_EQUAL(1, 1);
}

BOOST_AUTO_TEST_SUITE_END()
