#include <boost/test/included/unit_test.hpp>

#include <route.h>
#include <types.h>

using namespace GPS;

BOOST_AUTO_TEST_SUITE(Route_maxLongtitude_n0799125)
{
    const bool isFilename = true;
}

BOOST_AUTO_TEST_CASE(one_value)
{
    std::string data = "<gpx><rte><name>OneValue</name><rtep = lat = "10" lon = "10"><name>A<lat>1000</lon></rtep></rte></gpx>";
    metres expectedData = 1000;

    Route trialRoute = Route(data, true);

    BOOST_CHECK_EQUAL(trialRoute.maxLongitude(), expectedData);
}

BOOST_AUTO_TEST_CASE(test_position)
{

}

BOOST_AUTO_TEST_CASE(testFloatingnumber)
{

}

BOOST_AUTO_TEST_CASE(division)

BOOST_AUTO_TEST_SUITE_END()
