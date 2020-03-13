#include <boost/test/unit_test.hpp>
#include <limits>
#include "route.h"
#include "logs.h"

using namespace GPS;

const bool isFileName = true; // All GPX data in this suite is loaded from files.

BOOST_AUTO_TEST_SUITE(totalLength-n0786783)


BOOST_AUTO_TEST_CASE(Typical_Inputs_Small_Input)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK(route.totalLength(), 0.8)


}


BOOST_AUTO_TEST_CASE(Typical_Inputs_Three_Digit_Number)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK(route.totalLength(), 200)


}


BOOST_AUTO_TEST_CASE(Typical_Inputs_Five_Digit_Number)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK(route.totalLength(), 10500)


}


BOOST_AUTO_TEST_CASE(Negative_Inputs_Error_Case)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK(route.totalLength() < 0)

    
}


BOOST_AUTO_TEST_CASE(Positive_Inputs_Error_Case)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK(route.totalLength() > std::numeric_limits<double>::max())

    
}


BOOST_AUTO_TEST_CASE(Atypical_Inputs_Minimum_Edge_Case)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalLength(), 0)
}


BOOST_AUTO_TEST_CASE(Atypical_Input_Maximum_Edge_Case)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalLength(), std::numeric_limits<double>::max())

}


BOOST_AUTO_TEST_CASE(Typical_Input_Precision_Issue, * boost::unit_test::tolerance(0.001))
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalLength(), 100.001)


}

BOOST_AUTO_TEST_SUITE_END()
