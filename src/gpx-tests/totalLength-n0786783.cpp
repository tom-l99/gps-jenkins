#include <boost/test/unit_test.hpp>

#include "route.h"
#include "logs.h"

using namespace GPS;

const bool isFileName = true; // All GPX data in this suite is loaded from files.
const std::string defaultName = "Unnamed Route";

BOOST_AUTO_TEST_SUITE(totalLength-n0786783)


BOOST_AUTO_TEST_CASE(Typical_Inputs_If_Zero)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalLength(),0)
}


BOOST_AUTO_TEST_CASE(Negative_Inputs)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);

    BOOST_CHECK(route.totalLength() > -1)

}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Edge_Cases)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK(route.totalLength() > 0)


}

BOOST_AUTO_TEST_SUITE_END()
