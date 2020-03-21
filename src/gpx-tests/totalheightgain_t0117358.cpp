#include <boost/test/unit_test.hpp>

#include "logs.h"
#include "types.h"
#include "route.h"

using namespace GPS;

BOOST_AUTO_TEST_SUITE( Route_totalHeightGain )

const bool isFileName = true;
const metres horizontalGirdUNit = 10000;

BOOST_AUTO_TEST_CASE ( loop_through_all )  // first test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_UME.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0.40 );
}

BOOST_AUTO_TEST_CASE ( one_point_gain ) // second test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_KE.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0.179964);
}
BOOST_AUTO_TEST_CASE ( all_points_gain ) // third test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_UME.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0.40);
}

BOOST_AUTO_TEST_CASE ( declines_if_calculates ) // fourth test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_ULW.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0);
}

BOOST_AUTO_TEST_CASE ( after_declines_gain ) // fifth test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_ULWO.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0.179964);
}
BOOST_AUTO_TEST_CASE ( calculate_accurates_with_mix_drop_gain ) // sixth test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_ULXJ.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0.089982);
}
BOOST_AUTO_TEST_CASE ( same_height ) // seventh test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_ABC.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0);
}
BOOST_AUTO_TEST_CASE ( start_drop_end_gain ) // eighth test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_AME.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0.179964);
}
BOOST_AUTO_TEST_CASE ( all_negative ) // ninth test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_AMY.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0);
}
BOOST_AUTO_TEST_CASE ( start_negative_end_with_negative ) // tenth test
{
    Route route = Route(LogFiles::GPXRoutesDir + "T0117358_ALCO.gpx", isFileName);
    BOOST_CHECK_EQUAL ( route.totalHeightGain(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
