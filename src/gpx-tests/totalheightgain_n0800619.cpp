#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE(totalHeightGain_N0800619)

const metres defaulTotalHeightGain = 0;
const bool isFileName = true; // All GPX data in this suite is provided from files.

BOOST_AUTO_TEST_CASE(typicalInputs)
{
    const double percentageAccuracy = 0.00001;
    Route route = Route(LogFiles::GPXRoutesDir + "ABCD.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), 0.00000, percentageAccuracy );
}

BOOST_AUTO_TEST_CASE(typicalInputs2)
{
    const double percentageAccuracy = 0.00001;
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK_CLOSE( route.totalHeightGain(), 20000.00000, percentageAccuracy );
}

BOOST_AUTO_TEST_SUITE_END()
