#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE(MinLongitudeN0782914)

const bool isFileName = true;
std::string directory = LogFiles::GPXRoutesDir + "/N0782914/";

// Checks if the correct longitude value is returned
// when there is only a single value in the data set.
BOOST_AUTO_TEST_CASE(singleValue)
{
    Route route = Route(directory + "singleValue.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.118561625480652);
}

// Checks that the correct value is returned
// in a small data set.
BOOST_AUTO_TEST_CASE(smallDataset)
{
    Route route = Route(directory + "smallDataset.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.118561625480652);
}

// Checks that the correct value is returned
// in a medium data set.
BOOST_AUTO_TEST_CASE(mediumDataset)
{
    Route route = Route(directory + "mediumDataset.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.097061038017273);
}

// Checks that the correct longitude value is returned
// in a very large data set with many values.
BOOST_AUTO_TEST_CASE(largeDataset)
{
    Route route = Route(directory + "largeDataset.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.140192408561707);
}

// Checks that the correct minimum value is returned
// when the first value of the data set is the minimum value.
BOOST_AUTO_TEST_CASE(firstValueMinimum)
{
    Route route = Route(directory + "firstValueMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 1.097061038017273);
}

// Checks that the correct minimum value is returned
// when the middle value of the data set is the minimum value.
BOOST_AUTO_TEST_CASE(middleValueMinimum)
{
    Route route = Route(directory + "middleValueMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.097061038017273);
}

// Checks that the correct minimum value is returned
// when the last value of the data set is the minimum value.
BOOST_AUTO_TEST_CASE(lastValueMinimum)
{
    Route route = Route(directory + "lastValueMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.097061038017273);
}

// Checks that the correct value is returned
// when there are two lowest values equal to each other
// with different latitude values.
BOOST_AUTO_TEST_CASE(twoMinimums)
{
    Route route = Route(directory + "twoMinimums.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.097061038017273);
}

// Checks that the correct value is returned
// when there are three lowest values equal to each other
// with different latitude values.
BOOST_AUTO_TEST_CASE(threeMinimums)
{
    Route route = Route(directory + "threeMinimums.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.097061038017273);
}

// Checks that the correct longitude value is returned
// when the minimum value is a positive number among other positive numbers.
BOOST_AUTO_TEST_CASE(positiveMinimum)
{
    Route route = Route(directory + "positiveMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 1.120380163192749);
}

// Checks that the correct longitude value is returned
// when the minimum value is a negative number among positive numbers.
BOOST_AUTO_TEST_CASE(negativeMinimum)
{
    Route route = Route(directory + "negativeMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.120380163192749);
}

// Checks that the correct longitude value is returned
// when the minimum value is among results with high variance.
BOOST_AUTO_TEST_CASE(highVariance)
{
    Route route = Route(directory + "highVariance.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -65.120380163192749);
}

// Checks that the correct longitude value is returned
// when the minimum value is among results with low variance.
BOOST_AUTO_TEST_CASE(lowVariance)
{
    Route route = Route(directory + "lowVariance.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 1.000000000000046);
}

// Checks that the correct longitude value is returned
// when the minimum value is an integer.
BOOST_AUTO_TEST_CASE(integerMinimum)
{
    Route route = Route(directory + "integerMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 1);
}

// Checks that the correct longitude value is returned
// from a dataset containing values of mixed significant figures.
BOOST_AUTO_TEST_CASE(mixedSigFigs)
{
    Route route = Route(directory + "mixedSigFigs.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.118561625);
}

// Checks that the correct longitude value is returned
// when the minimum value is zero.
BOOST_AUTO_TEST_CASE(minValueZero)
{
    Route route = Route(directory + "minValueZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 0);
}

// Checks that the correct longitude value is returned
// from a dataset containing a value of negative zero.
BOOST_AUTO_TEST_CASE(minValueMinusZero)
{
    Route route = Route(directory + "minValueMinusZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
