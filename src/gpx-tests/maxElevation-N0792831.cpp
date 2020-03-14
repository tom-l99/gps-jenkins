#include <boost/test/unit_test.hpp>

#include "types.h"
#include "route.h"

using namespace GPS;


BOOST_AUTO_TEST_SUITE( maxElevation )

const bool isFileName = false;

BOOST_AUTO_TEST_CASE( oneValue )
{
    std::string data = "<gpx><rte><name>Onevalue</name><rtept lat=\"10\" lon=\"10\"><ele>1000</ele></rtept></rte></gpx>";


    metres expectedData = 1000;

    Route trialRoute = Route(data, isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );


}

BOOST_AUTO_TEST_CASE( multipleValues )
{
    std::string data = "<gpx><rte><name>MultipleValues</name><rtept lat='10' lon='10'><name>A</name><ele>100</ele></rtept><rtept lat='10' lon='10'><name>B</name><ele>1000</ele></rtept><rtept lat='10' lon='10'><name>C</name><ele>500</ele></rtept></rte></gpx>";


    metres expectedData = 573;

    Route trialRoute = Route(data, isFileName);

    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

}

//BOOST_AUTO_TEST_CASE( largeAmountOfPositions )
//{

//    std::string data = ;

//    metres expectedData = 2500;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}

//BOOST_AUTO_TEST_CASE( duplicateElevation )
//{

//    std::string data = ;

//    metres expectedData = ;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}

//BOOST_AUTO_TEST_CASE( extremeHigh )
//{

//    std::string data = ;

//    metres expectedData = ;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}

//BOOST_AUTO_TEST_CASE( elevation0 )
//{

//    std::string data = ;

//    metres expectedData = ;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}

//BOOST_AUTO_TEST_CASE( negativeValue )
//{

//    std::string data = ;

//    metres expectedData = ;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}

//BOOST_AUTO_TEST_CASE( extremeNegative )
//{

//    std::string data = ;

//    metres expectedData = ;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}

//BOOST_AUTO_TEST_CASE( mulitpleNegative )
//{

//    std::string data = ;

//    metres expectedData = ;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}

//BOOST_AUTO_TEST_CASE( missingElevation )
//{

//    std::string data = ;

//    metres expectedData = ;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}

//BOOST_AUTO_TEST_CASE( multipleValuesSomeMissing )
//{

//    std::string data = ;

//    metres expectedData = ;

//    Route trialRoute = Route(data, isFileName)

//    BOOST_CHECK_EQUAL( trialRoute.maxElevation(), expectedData );

//}




BOOST_AUTO_TEST_SUITE_END()

