#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE(MinLongitudeN0782914)

const bool isFileName = true;
std::string directory = LogFiles::GPXRoutesDir + "/N0782914/";

//SingleValue
BOOST_AUTO_TEST_CASE(singleValue)
{
    Route route = Route(directory + "singleValue.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.118561625480652);
}

//MultipleValues
BOOST_AUTO_TEST_CASE(multipleValues)
{
    Route route = Route(directory + "multipleValues.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.118561625480652);
}

//positiveMinimum
BOOST_AUTO_TEST_CASE(positiveMinimum)
{
    Route route = Route(directory + "positiveMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 1.120380163192749);
}

//negativeMinimum
BOOST_AUTO_TEST_CASE(negativeMinimum)
{
    Route route = Route(directory + "negativeMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.120380163192749);
}

//extremeLow
BOOST_AUTO_TEST_CASE(extremeLow)
{
    Route route = Route(directory + "extremeLow.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -30000.120380163192749);
}

//extremeHigh
BOOST_AUTO_TEST_CASE(extremeHigh)
{
    Route route = Route(directory + "extremeHigh.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 30000.120380163192749);
}

//emptyLong
BOOST_AUTO_TEST_CASE(emptyLong)
{
    Route route = Route(directory + "emptyLong.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.116346120834351);
}

//Lowest value of zero
BOOST_AUTO_TEST_CASE(minValueZero)
{
    Route route = Route(directory + "minValueZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 0);
}

//Large data set
BOOST_AUTO_TEST_CASE(largeDataset)
{
    Route route = Route(directory + "largeDataset.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.140192408561707);
}

BOOST_AUTO_TEST_SUITE_END()
