#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

/* Route.steepestGradient() should return the largest change in gradient (in degrees)
 * between to adjacent Positions. This change could be either a positive or negative
 * but the function should be able to calculate the largest change regardless of its
 * direction.
 *
 * However, this function requires there to be two Positions to compare against,
 * therefore it should throw a "std::domain_error" exception when only one
 * Position is given.
 *
 * This test suite starts by creating a test case that the function throws any
 * "std::domain_errors" correctly. This is one by feeding it gpx data that only
 * contains a single point.
 *
 * */

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
   Route route = Route(LogFiles::GPXRoutesDir + "AFKPU.gpx", isFileName);
   BOOST_CHECK_EQUAL( route.numPositions(), 0.00 );
}

/*BOOST_AUTO_TEST_CASE( constant_gradient_route )
{
   Route route = Route(LogFiles::GPXRoutesDir + NNumber + "UPS.gpx", isFileName);
   BOOST_CHECK_EQUAL( route.numPositions(), );
}
*/

BOOST_AUTO_TEST_SUITE_END()
