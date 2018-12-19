#include "rand.hpp"
#include <iostream>
#include <stdlib.h>

std::random_device generator;

// X = Disallowed; O = Allowed
//        X X X 0 0 X 0 0 0 0 
// Index: 0 1 2 3 4 5 6 7 8 9
//  Slot: - - - 0 1 - 2 3 4 5
//
// Search to see where slot fits in the bound

int random_natural(int bound, std::vector<int>& disallowed){

  int rand_bound = bound - disallowed.size() - 1;
  
  if (rand_bound < 0) {
    std::cerr << "Bad bound in random_natural()\n";
    abort();
  }

  std::uniform_int_distribution<int> natural_dist(0, rand_bound);

  int slot = natural_dist(generator);
  int slot_index = slot; 


  for (const int& dis_index : disallowed){

    // Move the slot index up one for each disallowed index before the slot
    if (dis_index <= slot_index) ++slot_index;
  }

  
  return slot_index;
}
