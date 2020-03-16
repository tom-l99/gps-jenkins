#include "maxlongitude_n0799202.h"
#include <boost/test/unit_test.hpp>

#include "route.h"

using namespace GPS;


const bool isFileName = false;

maxlongitude_n0799202::maxlongitude_n0799202()
{

}
BOOST_AUTO_TEST_CASE(London_longitude_data)
{
    const std::string gpxData ="<gpx><rte><name>London</name><rtept lat=\"51.507351\" lon=\"-0.127758\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "-0.127758" );

}

BOOST_AUTO_TEST_CASE(Paris_longitude_data)
{
    const std::string gpxData ="<gpx><rte><name>Paris</name><rtept lat=\"48.856613\" lon=\"2.352222\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "2.352222" );

}

BOOST_AUTO_TEST_CASE(Tolhuin_longitude_data)
{
    const std::string gpxData ="<gpx><rte><name>Tolhuin</name><rtept lat=\"-54.510570\" lon=\"-67.190840\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "-67.190840" );

}

BOOST_AUTO_TEST_CASE(Possitve_edge_case)
{
    const std::string gpxData ="<gpx><rte><name>Pacific</name><rtept lat=\"-54.510570\" lon=\"179.999999\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "179.999999" );
}

BOOST_AUTO_TEST_CASE(Negative_edge_case)
{
    const std::string gpxData ="<gpx><rte><name>Pacific</name><rtept lat=\"-54.510570\" lon=\"-179.999999\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "179.999999" );
}

BOOST_AUTO_TEST_CASE(decimal_place_boundary_case)
{
    const std::string gpxData ="<gpx><rte><name>Tolhuin</name><rtept lat=\"-54.510570\" lon=\"179.999999999999999\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "179.999999999999999" );
}
