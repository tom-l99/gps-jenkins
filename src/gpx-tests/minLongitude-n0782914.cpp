#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE(MinLongitudeN0782914)

/* Route.minLongitude() should return the minimum value of longitude from the route,
 * this will be taken from the number between two quotation marks (either " or ', but
 * most likely ") after the characters "lon=" within the <rtept> element.
 *
 * First, typical .gpx files are tested with no errors for generic use cases, including
 * data sets of varying lengths.
 *
 * We then test for extremely unlikely results, such as mixed significant figures in the data,
 * or a value of negative 0. These are unlikely to occur without some form of tampering,
 * but the program should be robust enough to be able to handle these cases even though they
 * are very unlikely to occur.
 */

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
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.084583401679993);
}

// Checks that the correct longitude value is returned
// in a very large data set with many values.
BOOST_AUTO_TEST_CASE(largeDataset)
{
    Route route = Route(directory + "largeDataset.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.140192408561707);
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
// when the minimum value is zero.
BOOST_AUTO_TEST_CASE(minValueZero)
{
    Route route = Route(directory + "minValueZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 0);
}

//High variance
BOOST_AUTO_TEST_CASE(highVariance)
{
    Route route = Route(directory + "highVariance.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -65.120380163192749);
}

//Low variance
BOOST_AUTO_TEST_CASE(lowVariance)
{
    Route route = Route(directory + "lowVariance.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 1.000000000000046);
}

//Very small difference
BOOST_AUTO_TEST_CASE(verySmallDifference)
{
    Route route = Route(directory + "verySmallDifference.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 1.000000000000045);
}

//First is minimum
BOOST_AUTO_TEST_CASE(firstValueMinimum)
{
    Route route = Route(directory + "firstValueMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 1.097061038017273);
}

//Middle is minimum
BOOST_AUTO_TEST_CASE(middleValueMinimum)
{
    Route route = Route(directory + "middleValueMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.097061038017273);
}

//Last is minimum
BOOST_AUTO_TEST_CASE(lastValueMinimum)
{
    Route route = Route(directory + "lastValueMinimum.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.097061038017273);
}

/*
//Multiple minimums
BOOST_AUTO_TEST_CASE(multipleMinimums)
{
    Route route = Route(directory + "multipleMinimums.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), );
}
*/

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
// from a dataset containing a value of negative zero.
BOOST_AUTO_TEST_CASE(minValueMinusZero)
{
    Route route = Route(directory + "minValueMinusZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
