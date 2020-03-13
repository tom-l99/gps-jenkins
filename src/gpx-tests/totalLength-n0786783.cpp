#include <boost/test/unit_test.hpp>

#include "route.h"
#include "logs.h"
#include "types.h"

using namespace GPS;

const bool isFileName = true; // All GPX data in this suite is loaded from files.
const metres maxTotalLength = 9999999999999;
std::string totalLengthTestDir = LogFiles::GPXRoutesDir + "/N0786783/";

BOOST_AUTO_TEST_SUITE(totalLength-n0786783)


BOOST_AUTO_TEST_CASE(Typical_Inputs_One_Digit_Number, * boost::unit_test::tolerance(0.001))
{

}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Two_Digit_Number,  * boost::unit_test::tolerance(0.001))
{

}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Three_Digit_Number,  * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Five_Digit_Number,  * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Six_Digit_Number, * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Nine_Digit_Number, * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Twelve_Digit_Number, * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Route_Is_Straight_Line, , * boost::unit_test::tolerance(0.001))
{


}


BOOST_AUTO_TEST_CASE(Route_Is_Changes_Direction_Once, , * boost::unit_test::tolerance(0.001))
{


}


BOOST_AUTO_TEST_CASE(Route_Goes_Every_Direction, , * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Route_Crosses_Point_Already_Crossed, , * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Route_Has_Single_Point, , * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Route_Has_Two_Points, , * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Route_Has_Three_Points, , * boost::unit_test::tolerance(0.001))
{


}


BOOST_AUTO_TEST_CASE(Route_Has_Four_Points, , * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Route_Has_Nine_Points, , * boost::unit_test::tolerance(0.001))
{


}

BOOST_AUTO_TEST_CASE(Route_Has_Two_Points_Same_Position, , * boost::unit_test::tolerance(0.001))
{


}



BOOST_AUTO_TEST_CASE(Atypical_Inputs_Minimum_Edge_Case)
{
    //Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), 0)
}

/*
BOOST_AUTO_TEST_CASE(Positive_Inputs_Error_Case)
{
    Route route = Route(LogFiles::GPXRoutesDir + "ABQWE.gpx", isFileName);
    //BOOST_CHECK(route.totalLength() > maxTotalLength)

    
}
*/

BOOST_AUTO_TEST_SUITE_END()
