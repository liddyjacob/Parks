#include "park.hpp"
#define BOOST_TEST_MODULE ParkTest
#include <boost/test/unit_test.hpp>

/* Check initialization and num_entries */
BOOST_AUTO_TEST_CASE(ParkInit){

  Park p1('c');
  Park p2;

  BOOST_CHECK_EQUAL(p1.trees_required(), 1);
  BOOST_CHECK_EQUAL(p1.char_rep(), 'c');

  BOOST_CHECK_EQUAL(p2.trees_required(), 1);
  BOOST_CHECK_EQUAL(p2.char_rep(), '?');
}

BOOST_AUTO_TEST_CASE(ParkEquality){
  
  Park p1('a', 2);
  Park p2('b', 2);
  
  //BOOST_CHECK_PREDICATE(p1, p2);
  BOOST_CHECK_EQUAL(p1, p1);
}
