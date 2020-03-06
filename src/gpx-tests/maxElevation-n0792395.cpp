#include <boost/test/unit_test.hpp>

#include "route.h"
#include "types.h"

using namespace GPS;

/* BOOST DESCRIPTION*/

BOOST_AUTO_TEST_SUITE( Route_maxElevation_N0792395 )

const bool isFileName = false;

const std::string NNumber = "/N0792395/"; //custom GPX data is loaded from this folder

//
BOOST_AUTO_TEST_CASE( elevation_absent )
{
   const std::string gpxData =
     "<gpx><rte><name>Test</name><rtept lat=\"0\" lon=\"0\"></rtept></rte></gpx>";
   metres expectedElevation = 0;

   Route route = Route(gpxData, isFileName);

   BOOST_CHECK_EQUAL( route.maxElevation(), expectedElevation);
}

//
BOOST_AUTO_TEST_CASE( elevation_empty )
{
   const std::string gpxData =
     "<gpx><rte><name>Test</name><rtept lat=\"0\" lon=\"0\"><ele></ele></rtept></rte></gpx>";
   metres expectedElevation = 0;

   Route route = Route(gpxData, isFileName);

   BOOST_CHECK_EQUAL( route.maxElevation(), expectedElevation );
}

//
BOOST_AUTO_TEST_CASE( natural_negative_elevation )
{
    const std::string gpxData =
      "<gpx><rte><name>Test</name><rtept lat=\"0\" lon=\"0\"><ele>-99999</ele></rtept></rte></gpx>";
    metres expectedElevation = -424;

    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.maxElevation(), expectedElevation );
}

//
BOOST_AUTO_TEST_CASE( natural_positive_elevation )
{
    const std::string gpxData =
      "<gpx><rte><name>Test</name><rtept lat=\"0\" lon=\"0\"><ele>-99999</ele></rtept></rte></gpx>";
    metres expectedElevation = 8848;

    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.maxElevation(), expectedElevation );
}

//
BOOST_AUTO_TEST_CASE( extreme_negative_elevation )
{
    const std::string gpxData =
      "<gpx><rte><name>Test</name><rtept lat=\"0\" lon=\"0\"><ele>-99999</ele></rtept></rte></gpx>";
    metres expectedElevation = -99999;

    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.maxElevation(), expectedElevation );
}

//
BOOST_AUTO_TEST_CASE( extreme_positive_elevation )
{
    const std::string gpxData =
      "<gpx><rte><name>Test</name><rtept lat=\"0\" lon=\"0\"><ele>99999</ele></rtept></rte></gpx>";
    metres expectedElevation = 99999;

    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.maxElevation(), expectedElevation );
}

BOOST_AUTO_TEST_SUITE_END()
