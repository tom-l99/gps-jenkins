#include <boost/test/unit_test.hpp>

#include "route.h"
#include "logs.h"
#include "types.h"

using namespace GPS;

const bool isFileName = false; // All GPX data in this suite is provided as strings.

metres defaultElevation = 0;

BOOST_AUTO_TEST_CASE( missing_elevation_element )
{
    const std::string gpxData =
      "<gpx><rte><name>MissingElement</name><rtept lat=\"0\" lon=\"0\"></rtept></rte></gpx>";

    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxElevation(), defaultElevation);
}

BOOST_AUTO_TEST_CASE( empty_elevation_element )
{
    const std::string gpxData =
      "<gpx><rte><name>EmptyElement</name><rtept lat=\"0\" lon=\"0\"><ele></ele></rtept></rte></gpx>";

    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxElevation(), defaultElevation);
}

BOOST_AUTO_TEST_CASE( one_point )
{
   Route route = Route(LogFiles::GPXRoutesDir + "Q.gpx", isFileName);
   BOOST_CHECK_EQUAL( route.maxElevation(), -20000.000000);
}


