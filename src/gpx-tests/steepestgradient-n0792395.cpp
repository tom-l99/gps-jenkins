#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

/* BOOST TEST SUITE DESCRIPTION */

BOOST_AUTO_TEST_SUITE( Route_steepestGradient_N0792395 )

const bool isFileName = true; // All GPX data in this suite is loaded from files.

const std::string NNumber = "/N0792395/"; //custom GPX data is loaded from this folder

//
BOOST_AUTO_TEST_CASE( single_route_point )
{
   Route route = Route(LogFiles::GPXRoutesDir + "Q.gpx", isFileName);
   BOOST_CHECK_THROW( route.numPositions(), std::domain_error );
}

//
BOOST_AUTO_TEST_CASE( flat_route )
{
   Route route = Route(LogFiles::GPXRoutesDir + "ABCD.gpx", isFileName);
   BOOST_CHECK_EQUAL( route.numPositions(), 0.00 );
}

BOOST_AUTO_TEST_SUITE_END()
