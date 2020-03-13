#include <boost/test/unit_test.hpp>

#include "route.h"
#include "logs.h"

BOOST_AUTO_TEST_SUITE (minElevation-N0806748)

const std::string defaultName = "N0806748";
const bool isFileName = false;

BOOST_AUTO_TEST_CASE (minElevation)
{
    Route route = Route(LogFiles::GPXRoutesDir + defaultName + "AGMSY.gpx", isFileName);
    BOOST_CHECK_EQUAL( route.minElevation(), 1 );
}

BOOST_AUTO_TEST_SUITE_END()
