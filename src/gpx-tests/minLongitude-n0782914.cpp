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
 * Next, we test for outliers ranging from very typical to extreme, which would
 * possibly be due to error in the measuring equipment. For longitude, extreme values must
 * be considered as the values '1.00000', '361.00000', and '5761.00000' are all valid
 * and refer to the same latitude.
 *
 * We then test for extremely unlikely results, such as an empty value for longitude,
 * mixed significant figures in the data, or a value of negative 0. There are unlikely
 * to occur without some form of tampering, but the program should be robust enough
 * to be able to handle these cases even though they are very unlikely to occur.
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
// when the minimum value is an extremely low number.
BOOST_AUTO_TEST_CASE(extremeLow)
{
    Route route = Route(directory + "extremeLow.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -30000.120380163192749);
}

// Checks that the correct longitude value is returned
// when the minimum value is an extremely high number.
BOOST_AUTO_TEST_CASE(extremeHigh)
{
    Route route = Route(directory + "extremeHigh.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 30000.118561625480652);
}

// Checks that the correct longitude value is returned
// when the minimum value is zero.
BOOST_AUTO_TEST_CASE(minValueZero)
{
    Route route = Route(directory + "minValueZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 0);
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
// from a dataset containing an empty value.
BOOST_AUTO_TEST_CASE(emptyLong)
{
    Route route = Route(directory + "emptyLong.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.116346120834351);
}

// Checks that the correct longitude value is returned
// from a dataset containing a value of negative zero.
BOOST_AUTO_TEST_CASE(minValueMinusZero)
{
    Route route = Route(directory + "minValueMinusZero.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), 0);
}

// Checks that the correct longitude value is returned
// when the dataset contains single quotation marks (')
// rather than double quotation marks (")
BOOST_AUTO_TEST_CASE(singleQuotation)
{
    Route route = Route(directory + "singleQuotation.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.minLongitude(), -1.120380163192749);
}


BOOST_AUTO_TEST_SUITE_END()
