#include "maxlongitude_n0795864.h"
#include <boost/test/unit_test.hpp>
#include "logs.h"
#include "types.h"
#include "route.h"
BOOST_AUTO_TEST_SUITE(maxlongitude_N0795864);
using namespace GPS;
const bool isFileName = false;
//accepted tests
BOOST_AUTO_TEST_CASE(NTU_longitude_data)
{
    std::cout<<("In NTU Boost maxlongitude\n");

    const std::string gpxData ="<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"-1.040540\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(gpxData), -1.04054 );
}
//boundaries
BOOST_AUTO_TEST_CASE(Min)
{
    std::cout<<("In minimum Boost maxlongitude\n");

    const std::string gpxData ="<gpx><rte><name>Minimum</name><rtept lat=\"52.946670\" lon=\"-180\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(gpxData), -180 );
}

BOOST_AUTO_TEST_CASE(Max)
{
    std::cout<<("In maximum Boost maxlongitude\n");

    const std::string gpxData ="<gpx><rte><name>Maximum</name><rtept lat=\"52.946670\" lon=\"180\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(gpxData), 180 );
}
BOOST_AUTO_TEST_CASE(Last)
{
    std::cout<<("In biggest last Boost maxlongitude\n");

    const std::string gpxData ="<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"-180\"></rtept></rte></gpx>,"
                                "<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"80\"></rtept></rte></gpx>,"
                                "<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"180\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(gpxData), 180);
}
BOOST_AUTO_TEST_CASE(Mid)
{
    std::cout<<("In biggest mid Boost maxlongitude\n");

    const std::string gpxData ="<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"-180\"></rtept></rte></gpx>,"
                                "<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"180\"></rtept></rte></gpx>,"
                                "<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"-80\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(gpxData), 180);
}
BOOST_AUTO_TEST_CASE(First)
{
    std::cout<<("In biggest first Boost maxlongitude\n");

    const std::string gpxData ="<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"180\"></rtept></rte></gpx>,"
                                "<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"-180\"></rtept></rte></gpx>,"
                                "<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"-80\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
    BOOST_CHECK_EQUAL( route.maxLongitude(gpxData), 180);
}
//error cases
BOOST_AUTO_TEST_CASE(ErrorLow)
{
    std::cout<<("In minimum Boost maxlongitude\n");

    const std::string gpxData ="<gpx><rte><name>Minimum</name><rtept lat=\"52.946670\" lon=\"-181\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
}

BOOST_AUTO_TEST_CASE(ErrorHigh)
{
    std::cout<<("In maximum Boost maxlongitude\n");

    const std::string gpxData ="<gpx><rte><name>NTU</name><rtept lat=\"52.946670\" lon=\"181\"></rtept></rte></gpx>";
    Route route = Route(gpxData, isFileName);
}
BOOST_AUTO_TEST_SUITE_END();
