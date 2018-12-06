#include "community.hpp"
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#define BOOST_TEST_MODULE CommunityTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(CommunityInit){
  
  Community m1(3);
  Community m2(4);
  Community m3(1);
  //Community c;

  BOOST_CHECK_EQUAL(m1.num_entries(), 9);
  BOOST_CHECK_EQUAL(m2.num_entries(), 16);
  BOOST_CHECK_EQUAL(m3.num_entries(), 1);

}



BOOST_AUTO_TEST_CASE(CommunityCreate_Parks){
  
  // Construct the park: c = d = 
  // A B C D
  // A B C D
  // A B C D
  // A B C D
  Community c(4);

  Community d(4);
  c.create_parks();
  d.create_parks();

  for (int i = 0; i < c.num_rows(); ++i){
    c.set_park(i, 
        {std::make_pair(0,i), 
         std::make_pair(1,i),
         std::make_pair(2,i),
         std::make_pair(3,i)});

    std::vector<std::pair<int, int> > row;
    for (int j = 0; j < d.num_cols(); ++j){
      row.push_back(std::make_pair(j, i));
    }

    d.set_park(i, row);
  }
 
  //std::cout << c;
  for (int i = 0; i < c.num_rows(); ++i){
    for (int j = 0; j < c.num_cols(); ++j){
      int next_i = (i + 1) % c.num_rows();
      int next_j = (j + 1) % c.num_cols();
      BOOST_CHECK_EQUAL(c[i][j], c[next_i][j]);
      BOOST_CHECK_PREDICATE(std::not_equal_to<Park> (), 
                            (*c[i][j])(*c[i][next_j]));
    }
  }
 }

BOOST_AUTO_TEST_CASE(communitySetRules){

  Community c(5);
  c.create_parks();
  
  for (int i = 0; i < c.num_rows(); ++i){
    c.set_park(i, 
        {std::make_pair(0,i), 
         std::make_pair(1,i),
         std::make_pair(2,i),
         std::make_pair(3,i),
         std::make_pair(4,i)});
  }

  Rule* r1 = new TreesAcross(1);
  Rule* r2 = new TreeRadius(1);
  
  c.set_rules({r1, r2});

  Solution s(5);
  
  s[0][0] = State::Tree;
  s[1][3] = State::Tree;
  s[2][1] = State::Tree;
  s[3][4] = State::Tree;
  s[4][2] = State::Tree;
  
  BOOST_CHECK(c.is_solved_by(s));
  s[0][1] = State::Tree;
  BOOST_CHECK(!c.is_solved_by(s));

}
