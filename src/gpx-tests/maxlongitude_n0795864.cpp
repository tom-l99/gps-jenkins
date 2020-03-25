#include <boost/test/unit_test.hpp>
#include "logs.h"
//#include "types.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE(maxlongitudeN0795864)

const bool isFileName = true;
std::string directory = LogFiles::GPXRoutesDir + "/N0795864";
//accepted tests
BOOST_AUTO_TEST_CASE(NTU_longitude_data)
{
    Route route = Route(directory + "NTUSinglePos.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), -1.04054 );
}
//boundaries
BOOST_AUTO_TEST_CASE(Min)
{
    Route route = Route(directory + "SinglePosMin.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), -180 );
}

BOOST_AUTO_TEST_CASE(Max)
{
    Route route = Route(directory + "SinglePosMax.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), 180 );
}
//multiple positions
BOOST_AUTO_TEST_CASE(Last)
{
    Route route = Route(directory + "MultiplePosLast.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), 180);
}
BOOST_AUTO_TEST_CASE(Mid)
{
    Route route = Route(directory + "MultiplePosMid.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), 180);
}
BOOST_AUTO_TEST_CASE(First)
{
    Route route = Route(directory + "MultiplePosFirst.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), 180);
}
//error cases already taken care of

BOOST_AUTO_TEST_SUITE_END()
