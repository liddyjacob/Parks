
#define BOOST_TEST_MODULE SolutionTest
#include <boost/test/unit_test.hpp>

/* Check initialization and num_entries */
BOOST_AUTO_TEST_CASE(SolutionInit)
{
  Rules r = {TREES_PER_ROW(1)};   
  //                        rows, trees per row/col           
  Solution s = random_solution(4, );


}
