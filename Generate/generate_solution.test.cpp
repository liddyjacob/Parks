#include "community.hpp"
#include "generate_solution.hpp"
#include "rules.hpp"
#define BOOST_TEST_MODULE GenerateTest
#include <boost/test/unit_test.hpp>

/* Check initialization and num_entries */
BOOST_AUTO_TEST_CASE(SolutionGenerate)
{
  TreesAcross r1(1);
  TreeRadius r2(1); 

  Community c(6); // Trivial community
  c.create_parks();

  for (int i = 0; i < c.num_rows(); ++i){
    
    std::vector<std::pair<int, int> > row;
    for (int j = 0; j < c.num_cols(); ++j){
      row.push_back(std::make_pair(j, i));
    }

    c.set_park(i, row);
  }

  c.set_rules({&r1, &r2});

  Solution s = generate_solution(6, r1, r2);
  std::cerr << s;
  BOOST_CHECK(c.is_solved_by(s));
 
}
