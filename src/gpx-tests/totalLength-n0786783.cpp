#include <boost/test/unit_test.hpp>

#include "route.h"
#include "logs.h"
#include "types.h"


namespace utf = boost::unit_test;
using namespace GPS;


BOOST_AUTO_TEST_SUITE(totalLength_n0786783)


const bool isFileName = true; // All GPX data in this suite is loaded from files.
const double tol = 0.0001;


BOOST_AUTO_TEST_CASE(Extreme_Input_Three_Digit_Number,  * utf::tolerance(tol)) //checking a very small route size, 3 digits long (very small - hundred metres).
{
     metres expectedResult = 111.195;

     Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AB.gpx", isFileName);
     BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Typical_Input_Five_Digit_Number,  * utf::tolerance(tol)) //checking an average route size, 5 digits long (average - tens of thousands of metres).
{
    metres expectedResult = 30022.5;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCB.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Typical_Input_Six_Digit_Number, * utf::tolerance(tol))     //checking a long route size, 6 digits (long - hundred thousand metres)
{
    metres expectedResult = 121525;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AGM.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);

}


BOOST_AUTO_TEST_CASE(Typical_Input_Eight_Digit_Number, * utf::tolerance(tol)) //checking a very long route size but still not extreme, 8 digits long (larger end of inputs - millions)
{
    metres expectedResult = 2233405.18;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/spiral.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);

}


BOOST_AUTO_TEST_CASE(Extreme_Input_Twelve_Digit_Number, * utf::tolerance(tol))  //checking the largest size of a route, with 12 digits long (extreme value - hundred billions of metres).
{
    metres expectedResult = 400045320843;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABGLKF.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Is_Straight_Line, * utf::tolerance(tol))  // checking path/route shape that is a straight line on the same level (no slope).
{
    metres expectedResult= 40030;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCDE.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);

}


BOOST_AUTO_TEST_CASE(Route_Changes_Direction_Once,* utf::tolerance(tol)) //checking a path/route shape that changes direction once (e.g East direction initially then South).
{
    metres expectedResult= 239735;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCDEJOTY.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Downward_Slope,* utf::tolerance(tol))  //checking a straight line path that goes on a downward slope (decreasing elevation).
{
    metres expectedResult = 121525;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/MSY.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Upward_Slope,* utf::tolerance(tol)) //checking a straight line path that goes on an upward slope (increasing elevation).
{
    metres expectedResult = 121525;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AGM.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Looped,* utf::tolerance(tol))  //checking a path/route shape that loops back to the point it began with.
{
    metres expectedResult = 239735;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/loop.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Spiral,* utf::tolerance(tol))  //checking a path/route shape similar to a spiral.
{
    metres expectedResult = 2233405.18;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/spiral.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Goes_Back_On_Itself,* utf::tolerance(tol))      //checking a path/route shape which ends up changing direction so that the path goes back onitself.
{                                                                       //specifically, distance shouldn't be subtracted as the path goes back on itself.
    metres expectedResult = 30022.5;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCB.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);

}


BOOST_AUTO_TEST_CASE(Route_Goes_Every_Direction, * utf::tolerance(tol))     //checking a path/route shape which manages to travel in every direction (North, East, South and West).
{
    metres expectedResult = 400045320843.68;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABGLKF.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Has_Single_Point)                        //checking a route with only one point, meaning 0 distance should be travelled.
{
    Route route = Route(LogFiles::GPXRoutesDir + "Q.gpx" , isFileName);
    BOOST_CHECK_SMALL(route.totalLength(), tol);

}


BOOST_AUTO_TEST_CASE(Route_Has_Two_Points, * utf::tolerance(tol))  //checking route with only two points.
{
     metres expectedResult = 111.195;

     Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AB.gpx", isFileName);
     BOOST_TEST(route.totalLength() == expectedResult);

}


BOOST_AUTO_TEST_CASE(Route_Has_Three_Points,* utf::tolerance(tol))  //checking a route with three points.
{
    metres expectedResult = 121525;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/AGM.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Has_Four_Points, * utf::tolerance(tol))  //checking a route with four points.
{
    metres expectedResult = 30022.5;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCB.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);

}


BOOST_AUTO_TEST_CASE(Route_Has_Nine_Points, * utf::tolerance(tol))   //checking a route with nine points.
{
     metres expectedResult= 239735;

     Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/ABCDEJOTY.gpx", isFileName);
     BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Has_Every_Point, * utf::tolerance(tol))  //checking a route that uses every single point available.
{
    metres expectedResult = 2233405.18;

    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/spiral.gpx", isFileName);
    BOOST_TEST(route.totalLength() == expectedResult);
}


BOOST_AUTO_TEST_CASE(Route_Has_Two_Points_Same_Position)   //checking that a route with the 2 points which are the same returns 0, as no distance would be travelled.
{
    Route route = Route(LogFiles::GPXRoutesDir  + "/N0786783/twoPointSamePosition.gpx", isFileName);
    BOOST_CHECK_SMALL(route.totalLength(), tol);
}


BOOST_AUTO_TEST_CASE(No_Route)   //check that an empty route, no points, doesn't throw an error and is equal to 0 (As no distance is travelled).
{
     Route route = Route(LogFiles::GPXRoutesDir + "/N0786783/emptyRoute.gpx", isFileName);
     BOOST_CHECK_NO_THROW(route.totalLength());
     BOOST_CHECK_SMALL(route.totalLength(), tol);
}


BOOST_AUTO_TEST_CASE(Invalid_Data)  //check that an invalid_argument is caught when invalid data such as an extreme value of longitude and latitude is processed.
{

    //Route route = Route(LogFiles::GPXRoutesDir + "/N0786783/invalidData.gpx", isFileName);
    //BOOST_CHECK_THROW(route.totalLength(), std::invalid_argument);
}


BOOST_AUTO_TEST_SUITE_END()
