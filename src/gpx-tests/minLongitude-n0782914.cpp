#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE(RouteMinLongitudeN0782914)

const bool isFileName = true;
std::string directory = LogFiles::GPXRoutesDir + "/N0782914/";

//SingleValue
BOOST_AUTO_TEST_CASE( singleValue)
{
    Route route = Route(directory + "singleValue.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.minLongitude(), 1 );
}


//MultipleValues

//extremeLow

//emptyLong

//Lowest value of zero

//Large data set

BOOST_AUTO_TEST_SUITE_END()
