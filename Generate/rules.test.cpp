#include "rules.hpp"
#define BOOST_TEST_MODULE SolutionTest
#include <boost/test/unit_test.hpp>

/* Check initialization and num_entries */
BOOST_AUTO_TEST_CASE(SolutionInit)
{
  Rule* r1 = new TreesAcross(3);
  Rule* r2 = new TreeRadius(1);


}
