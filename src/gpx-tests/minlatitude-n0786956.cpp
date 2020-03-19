#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE( minLatitude )

const bool isFileName = true;
std::string gpxData = LogFiles::GPXRoutesDir + "/N0786956/";

BOOST_AUTO_TEST_CASE(samePosition,* utf::tolerance(0.2))
{
    double expectedResult = 0.179988;
    Route route = Route(gpxData+"AA.gpx",isFileName);

    BOOST_TEST(route.minLatitude() == expectedResult);
}


BOOST_AUTO_TEST_CASE(highestNegativeValue,* utf::tolerance(0.1))
{
    double expectedResult = -0.089982;
    Route route = Route(gpxData+"SY.gpx",isFileName);

    BOOST_TEST(route.minLatitude() == expectedResult);
}

//BOOST_AUTO_TEST_CASE(,* utf::tolerance(0.1))
//{

//}



BOOST_AUTO_TEST_SUITE_END()
