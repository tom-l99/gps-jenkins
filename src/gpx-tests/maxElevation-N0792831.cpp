#include <boost/test/unit_test.hpp>

#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( maxElevation )



BOOST_AUTO_TEST_CASE( oneValue )
{
    std::string data = "<gpx><rte><name>Onevalue</name><rtept lat="10" lon="10"><name>A</name><ele>1000</ele></rtept></rte></gpx>";
    metres expectedData = 1000;

    Route trialRoute = Route(data, false);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );


}

BOOST_AUTO_TEST_CASE( multipleValues )
{
    std::string data = "<gpx><rte><name>MultipleValues</name><rtept lat="10" lon="10"><name>A</name><ele>100</ele></rtept><rtept lat="10" lon="10"><name>B</name><ele>1000</ele></rtept><rtept lat="10" lon="10"><name>C</name><ele>500</ele></rtept></rte></gpx>";


    metres expectedData = 1000;

    Route trialRoute = Route(data, false);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}


//Test for a large amount of positions
//Test for duplicate positions
//Test very large and very small altitudes
//Negative values
//High negative values


BOOST_AUTO_TEST_SUITE_END()

