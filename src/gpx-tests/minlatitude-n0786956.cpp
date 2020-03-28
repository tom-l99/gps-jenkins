#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;
namespace utf = boost::unit_test;

BOOST_AUTO_TEST_SUITE(minLatitude)

const bool isFileName = true;
const double tolerance = 0.0001;
std::string gpxData = LogFiles::GPXRoutesDir + "/N0786956/";


//Check that tests should pass even with a value zero
BOOST_AUTO_TEST_CASE( valueZero, * utf::tolerance(0.001))
{
    double input = 0;
    Route route = Route(gpxData+"AGSY.gpx",isFileName);
    BOOST_TEST(route.minLatitude() == input);
}

//
BOOST_AUTO_TEST_CASE(samePosition)
{
    Route route = Route(gpxData+"A.gpx",isFileName);
    BOOST_CHECK_CLOSE(route.minLatitude(),0.179964,tolerance);
}

//
BOOST_AUTO_TEST_CASE( singlePositiveWholeValue )
{
    Route route = Route(gpxData+"A.gpx",isFileName);
    BOOST_CHECK_EQUAL(route.minLatitude(),1);
}

//BOOST_AUTO_TEST_CASE(samePosition,* utf::tolerance(0.2))
//{
//    double expectedResult = 0.179988;
//    Route route = Route(gpxData+"AA.gpx",isFileName);

//    BOOST_TEST(route.minLatitude() == expectedResult);
//}

//BOOST_AUTO_TEST_CASE(highestNegativeValue,* utf::tolerance(0.1))
//{
//    double expectedResult = -0.089982;
//    Route route = Route(gpxData+"SY.gpx",isFileName);

//    BOOST_TEST(route.minLatitude() == expectedResult);
//}

BOOST_AUTO_TEST_SUITE_END()
