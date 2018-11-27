#include "community.hpp"
#include <iostream>
#include <functional>
#include <vector>
#define BOOST_TEST_MODULE CommunityTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(CommunityInit){
  
  Community m1(3,3);
  Community m2(4,2);
  Community m3(1,1);
  //Community c;

  BOOST_CHECK_EQUAL(m1.num_entries(), 9);
  BOOST_CHECK_EQUAL(m2.num_entries(), 8);
  BOOST_CHECK_EQUAL(m3.num_entries(), 1);

}


// Removed test case: incorrect to current interface
/*
BOOST_AUTO_TEST_CASE(CommunityConstruct){

  Community c(4,4);

  std::vector<Park*> p_vect = {new Park('A'), new Park('B'), new Park('C'), new Park('D')};
  // Construct the park:
  // A B C D
  // A B C D
  // A B C D
  // A B C D

  for (int i = 0; i < c.num_rows(); ++i)
    for (int j = 0; j < c.num_cols(); ++j)
      c[i][j] = p_vect[j];

  std::cout << c;

  for (int i = 0; i < c.num_rows(); ++i){
    for (int j = 0; j < c.num_cols(); ++j){
      int next_i = (i + 1) % c.num_rows();
      int next_j = (j + 1) % c.num_cols();

      BOOST_CHECK_EQUAL(c[i][j], c[next_i][j]);
      BOOST_CHECK_PREDICATE(std::not_equal_to<Park> (), (*c[i][j])(*c[i][next_j]));
    }
  }
  //BOOST_CHECK p_vect[i][j] = &p_vect[j];
}
*/

BOOST_AUTO_TEST_CASE(CommunityCreate_Parks){
  Community c(4);
  c.Create_Parks();

}
