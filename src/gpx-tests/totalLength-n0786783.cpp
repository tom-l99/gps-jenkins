#include <boost/test/unit_test.hpp>

#include "route.h"
#include "logs.h"
#include "types.h"

using namespace GPS;



BOOST_AUTO_TEST_SUITE(totalLength_n0786783)

const bool isFileName = true; // All GPX data in this suite is loaded from files.


BOOST_AUTO_TEST_CASE(Typical_Inputs_Three_Digit_Number,  * boost::unit_test::tolerance(0.001))
{
    //use AB.gpx
     metres expectedResult = 111.195;
     //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AB.gpx", isFileName);
     //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Five_Digit_Number,  * boost::unit_test::tolerance(0.001))
{
    //use ABCB.gpx
    metres expectedResult = 30022.5;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCB.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);

}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Six_Digit_Number, * boost::unit_test::tolerance(0.001))
{
    //use AGM.gpx
    metres expectedResult = 121525;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AGM.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);

}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Eight_Digit_Number, * boost::unit_test::tolerance(0.001))
{
    //use spiral.gpx
    metres expectedResult = 24369151.240;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/spiral.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);

}

BOOST_AUTO_TEST_CASE(Typical_Inputs_Twelve_Digit_Number, * boost::unit_test::tolerance(0.001))
{
    //use ABGLKF.gpx
    metres expectedResult = 400045320843.68;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABGLKF.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}

BOOST_AUTO_TEST_CASE(Route_Is_Straight_Line, * boost::unit_test::tolerance(0.001))
{
   //use ABCDE.gpx
    metres expectedResult= 239735;
    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCDE.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);

}


BOOST_AUTO_TEST_CASE(Route_Changes_Direction_Once,* boost::unit_test::tolerance(0.001))
{
   //use ABCDEJOYT.gpx
    metres expectedResult= 239735;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCDEJOTY.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);

}


BOOST_AUTO_TEST_CASE(Route_Downward_Slope,* boost::unit_test::tolerance(0.001))
{
    metres expectedResult = 121525;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/MSY.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Upward_Slope,* boost::unit_test::tolerance(0.001))
{

    //use AGM.gpx
    metres expectedResult = 121525;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AGM.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Looped,* boost::unit_test::tolerance(0.001))
{
    //use loop.gpx
    metres expectedResult = 239735;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/loop.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Spiral,* boost::unit_test::tolerance(0.001))
{
    //use spiral.gpx
    metres expectedResult = 24369151.240;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/spiral.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Goes_Back_On_Itself,* boost::unit_test::tolerance(0.001))
{
    //use ABCB.gpx
    metres expectedResult = 30022.5;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCB.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);

}

BOOST_AUTO_TEST_CASE(Route_Goes_Every_Direction, * boost::unit_test::tolerance(0.001))
{
    //use ABGLKF.gpx
    metres expectedResult = 400045320843.68;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABGLKF.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}

BOOST_AUTO_TEST_CASE(Route_Has_Single_Point, * boost::unit_test::tolerance(0.001))
{
    Route route = Route(LogFiles::GPXRoutesDir + "Q.gpx" , isFileName);
    BOOST_CHECK_EQUAL(route.totalLength(), 0);

}

BOOST_AUTO_TEST_CASE(Route_Has_Two_Points, * boost::unit_test::tolerance(0.001))
{
    //use AB.gpx
     metres expectedResult = 111.195;
     //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AB.gpx", isFileName);
     //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);

}

BOOST_AUTO_TEST_CASE(Route_Has_Three_Points, * boost::unit_test::tolerance(0.001))
{
    //use AGM.gpx
    metres expectedResult = 121525;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AGM.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Has_Four_Points, * boost::unit_test::tolerance(0.001))
{
    //use ABCB.gpx
    metres expectedResult = 30022.5;
   // Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCB.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);

}

BOOST_AUTO_TEST_CASE(Route_Has_Nine_Points, * boost::unit_test::tolerance(0.001))
{
    //use ABCDEJOTY.gpx
     metres expectedResult= 239735;
     Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCDEJOTY.gpx", isFileName);
     //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}

BOOST_AUTO_TEST_CASE(Route_Has_Every_Point, * boost::unit_test::tolerance(0.001))
{

    //use spiral.gpx
    metres expectedResult = 24369151.240;
    //Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/spiral.gpx", isFileName);
    //BOOST_CHECK_EQUAL(route.totalLength(), expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Has_Two_Points_Same_Position)
{
    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/twoPointRouteWithSamePositions.gpx", isFileName);
    BOOST_CHECK_EQUAL(route.totalLength(), 0);
}



BOOST_AUTO_TEST_CASE(No_Route_Edge_Case)
{
   // Route route = Route(LogFiles::GPXRoutesDir + "/N0786783/emptyRoute.gpx", isFileName);
   // BOOST_CHECK_(route.totalLength(), 0);
}



BOOST_AUTO_TEST_SUITE_END()
