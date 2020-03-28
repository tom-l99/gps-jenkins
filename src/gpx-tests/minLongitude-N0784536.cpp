#include <boost/test/unit_test.hpp>

#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( minLongtitude_Route_N0784536)

const bool isFileName = false;

//tests typical values being evaluated
BOOST_AUTO_TEST_CASE( typical_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"0\" lon=\"100.0\"></rtept><rtept lat=\"0\" lon=\"101.0\"></rtept><rtept lat=\"0\" lon=\"103.0\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), 100.0 );
}

//tests function can return as an integer
BOOST_AUTO_TEST_CASE( integer_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"0\" lon=\"100\"></rtept><rtept lat=\"0\" lon=\"101\"></rtept><rtept lat=\"0\" lon=\"103\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), 100 );
}

//tests that the minimum boundary of value has been set correctly
BOOST_AUTO_TEST_CASE( extreme_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"0\" lon=\"-180.0\"></rtept><rtept lat=\"0\" lon=\"180.0\"></rtept><rtept lat=\"0\" lon=\"0\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), -100.0 );
}

//tests that it can return a 0 value
BOOST_AUTO_TEST_CASE( zero_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"0\" lon=\"0\"></rtept><rtept lat=\"0\" lon=\"0\"></rtept><rtept lat=\"0\" lon=\"0\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), 0 );
}

//tests that function ignores values outside of boundaries
BOOST_AUTO_TEST_CASE( ignore_erroneous_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"0\" lon=\"-200.0\"></rtept><rtept lat=\"0\" lon=\"-70.0\"></rtept><rtept lat=\"0\" lon=\"0\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), -70.0 );
}

//tests that it can return a 0 value when 0 is negative
BOOST_AUTO_TEST_CASE( negative_zero_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"1.2\" lon=\"0\"></rtept><rtept lat=\"1.1\" lon=\"0\"></rtept><rtept lat=\"-0\" lon=\"0\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), 0 );
}

//tests that the function fetches all digits supplied
BOOST_AUTO_TEST_CASE( digits_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"0\" lon=\"-1.74834\"></rtept><rtept lat=\"0\" lon=\"-1.74564\"></rtept><rtept lat=\"0\" lon=\"-1.87643\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), -1.74564 );
}

//tests that the function does not round the values
BOOST_AUTO_TEST_CASE( rounding_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"0\" lon=\"0.00002\"></rtept><rtept lat=\"0\" lon=\"0.00001\"></rtept><rtept lat=\"0\" lon=\"0.00003\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), 0.00001 );
}

//tests that the function returns correct value when repeated
BOOST_AUTO_TEST_CASE( repeating_min_longtitude )
{
    const std::string gpxData =
      "<gpx><rte><name>MyRoute</name><rtept lat=\"0\" lon=\"0.00002\"></rtept><rtept lat=\"0\" lon=\"0.00001\"></rtept><rtept lat=\"0\" lon=\"0.00001\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);

    BOOST_CHECK_EQUAL( route.minLongitude(), 0.00001 );
}


BOOST_AUTO_TEST_SUITE_END()






