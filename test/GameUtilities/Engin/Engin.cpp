#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <GameUtilities/Engin/Engin.h>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( free_test_function )
{
	GU::Engin::Engin engin;
    BOOST_CHECK( true /* test assertion */ );
}

