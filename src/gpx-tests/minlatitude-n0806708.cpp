#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;
using namespace std;

BOOST_AUTO_TEST_SUITE (Route_minLatitude_N0806708)

const bool isFileName = true;
string directory = LogFiles::GPXRoutesDir + "/N0806708/";

BOOST_AUTO_TEST_CASE (onePosition)
{
    Route testData = Route(directory + "onePosition.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0.0179964);
}

BOOST_AUTO_TEST_CASE (zeroLatitude)
{
    Route testData = Route(directory + "zeroLatitude.gpx", isFileName);
    BOOST_CHECK_EQUAL(testData.minLatitude(), 0);
}

//BOOST_AUTO_TEST_CASE (typicalLatitudeInput)
//{

//}

//BOOST_AUTO_TEST_CASE (manyPositions)
//{

//}

//BOOST_AUTO_TEST_CASE (duplicatePositions)
//{

//}


//BOOST_AUTO_TEST_CASE (closePositions)
//{
//
//}

//BOOST_AUTO_TEST_CASE (distantPositions)
//{

//}
//BOOST_AUTO_TEST_CASE (sameLatitudeDifferentLongitude)
//{

//}

//BOOST_AUTO_TEST_CASE (smallPositiveLatitude)
//{

//}

//BOOST_AUTO_TEST_CASE (smallNegativeLatitude)
//{

//}

// edge cases

//BOOST_AUTO_TEST_CASE (latitudeBorderLow)
//{

//}

//BOOST_AUTO_TEST_CASE (latitudeBorderHigh)
//{

//}


// error cases

//BOOST_AUTO_TEST_CASE (latitudeTooLow)
//{

//}

//BOOST_AUTO_TEST_CASE (latitudeTooHigh)
//{

//}

//BOOST_AUTO_TEST_CASE (emptyLatitude)
//{

//}

//BOOST_AUTO_TEST_CASE (boostToleranceFLTPNT)
//{

//}

BOOST_AUTO_TEST_SUITE_END()
