#include <boost/test/unit_test.hpp>

#include "logs.h"
#include <stdexcept>
#include "route.h"

using namespace GPS;

/*BOOST TEST DESCRIPTION*/

BOOST_AUTO_TEST_SUITE( Route_steepestGradient )

const bool isFileName = true; // All GPX data in this suite is loaded from files.

BOOST_AUTO_TEST_CASE( single_point_route )
{
   Route route = Route(LogFiles::GPXRoutesDir + "Q.gpx", isFileName);
   BOOST_CHECK_THROW( route.steepestGradient(), std::domain_error );
}

BOOST_AUTO_TEST_SUITE_END()
