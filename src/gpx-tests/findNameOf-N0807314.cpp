#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "route.h"

using namespace GPS;

/* Returns the name of the Position, or "Unnamed Position" if the point is nameless.
 * Throws a std::domain_error exception if that Position is not within "granularity"
 * of any stored Positions.
 */

BOOST_AUTO_TEST_SUITE( Find_Name_Of_N0807314 )

const bool isFileName = true; // All GPX data in this suite is loaded from files.
const std::string defaultName = "Unnamed Position";

BOOST_AUTO_TEST_SUITE_END()
