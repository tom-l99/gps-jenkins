#include "maxlongitude_n0799202.h"
#include <boost/test/unit_test.hpp>

#include "route.h"

using namespace GPS;


const bool isFileName = false;


maxlongitude_n0799202::maxlongitude_n0799202()
{

}
//Typical input of London's GPX data.
BOOST_AUTO_TEST_CASE(London_longitude_data)
{
    const std::string gpxData ="<gpx><rte><name>London</name><rtept lat=\"51.507351\" lon=\"-0.127758\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "-0.127758" );

}
//Typical input of Paris's GPX data.
BOOST_AUTO_TEST_CASE(Paris_longitude_data)
{
    const std::string gpxData ="<gpx><rte><name>Paris</name><rtept lat=\"48.856613\" lon=\"2.352222\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "2.352222" );

}
//Typical input of Tolhuin's GPX data
BOOST_AUTO_TEST_CASE(Tolhuin_longitude_data)
{
    const std::string gpxData ="<gpx><rte><name>Tolhuin</name><rtept lat=\"-54.510570\" lon=\"-67.190840\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "-67.190840" );

}
//Test for maximum valid values.
BOOST_AUTO_TEST_CASE(Possitve_edge_case)
{
    const std::string gpxData ="<gpx><rte><name>Pacific</name><rtept lat=\"-54.510570\" lon=\"180.0\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "180.0" );
}

//Test for minimum valid value.
BOOST_AUTO_TEST_CASE(Negative_edge_case)
{
    const std::string gpxData ="<gpx><rte><name>Pacific</name><rtept lat=\"-54.510570\" lon=\"-180.0\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "-180.0" );
}

//Test for maximum valid decimal values.
BOOST_AUTO_TEST_CASE(decimal_place_boundary_case)
{
    const std::string gpxData ="<gpx><rte><name>Tolhuin</name><rtept lat=\"-54.510570\" lon=\"179.999999999999999\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "179.999999999999999" );
}

//Test for minimum valid decimal values.
BOOST_AUTO_TEST_CASE(negative_decimal_place_boundary_case)
{
    const std::string gpxData ="<gpx><rte><name>Tolhuin</name><rtept lat=\"-54.510570\" lon=\"-179.999999999999999\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), "-179.999999999999999" );
}

//Tests values that exceed valid ranges.
BOOST_AUTO_TEST_CASE(Above_Max_Value)
{
    const std::string gpxData ="<gpx><rte><name>Tolhuin</name><rtept lat=\"-54.510570\" lon=\"180.1\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), NULL );
}

//Tests values that exceed valid ranges.
BOOST_AUTO_TEST_CASE(Below_Minimum_value)
{
    const std::string gpxData ="<gpx><rte><name>Tolhuin</name><rtept lat=\"-54.510570\" lon=\"-180.1\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), NULL );
}

//Test for empty value.
BOOST_AUTO_TEST_CASE(No_Longitude_value)
{
    const std::string gpxData ="<gpx><rte><name>Tolhuin</name><rtept lat=\"-54.510570\" lon=\" \"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(), NULL);
}
