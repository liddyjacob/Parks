#include "generate_solution.hpp"
#include "rand.hpp"
#include "state.hpp"
#include "rules.hpp"
#include "utilities.hpp" // within_radius
// REQUIRE acrossrule and radius rule.
// Later iterations of this generator
// may allow for more generic rules 
Solution generate_solution(int size, TreesAcross& acrossrule, 
                                     TreeRadius&  radiusrule){

  // We need to make sure there is enough spaces to guarentee a solution 
  // Each tree takes about (radius + 1)^2 spaces, if packed nicely 
  // There will be s * num_across trees, for a minimum of 
  // s * num_trees * (radius + 1)^2 spaces needed.
  //
  // So 
  //
  // s^2 > s * num_trees * (radius + 1)^2
  // s   > num_trees * (radius + 1)*2
  // This gives us s >= 5 for num_trees = radius = 1
  // Also gives us s >= 9 for num_trees = 2, radius = 1;
  // 
  // These numbers match the puzzles on apps I have played
  int radius = radiusrule.radius;
  int num_trees = acrossrule.num;

  if (size <= (radius + 1) * (radius + 1) * num_trees){
    std::cerr << "Solution is not possible to make?\n"; 
    return Solution(0);
  }

  Solution s(size);

  // Only handle one tree per row/col
  std::vector<int> disallowed;
  if (radius != 1) { 
    std::cerr << "Radius 1 only supported right now\n";
    abort();
  }

  // This section relies on radius = 1
  if (num_trees == 1){

    for (int i = 0; i < size; ++i){
      
      // Disallow marked points:
      disallowed.clear();
      for (int j = 0; j < size; ++j){
        
        if (s[i][j] == State::Marked){
          disallowed.push_back(j);
          continue;
        }
        
        if (fails_base_case(std::make_pair(i, j), s)){ 
          disallowed.push_back(j);
          continue;
        }

      }

      // New point:
      int j = random_natural(size, disallowed);
      
      mark_within_radius(radius, std::make_pair(i, j), s);
      
      mark_row(i, s);
      mark_col(j, s);
      
      s[i][j] = State::Tree;
    }
  }


  return s;
}

bool fails_base_case(std::pair<int, int> pair, Solution s){ 
  int radius = 1;// Vary later
  
  int i = pair.first;
  int j = pair.second;
  int max = s.num_rows();
  int diff = max - i - 1;   // 
  if (diff > 3) { return false; } 
  if (diff <= 1) { return false; }

  mark_within_radius(radius, std::make_pair(i, j), s);
      
  mark_row(i, s);
  mark_col(j, s);
 
  int j_hole = 0;
  int i_next = i + 1;

  for (j_hole; j_hole < max; ++j_hole){
    // Hole = empty space:
    if (s[max - 1][j_hole] == State::Empty) break;
  }

  // Make a solution whose top is the same but whose bottom is 
  // a diff x diff square:
  Solution s_bad = s;

  // Very crude way of checking for a diffxdiff hole
  // at the bottom of s
  for (int i_bad = i_next; i_bad < max; ++i_bad){
    for (int j_bad = 0; j_bad < max; ++j_bad){
      s_bad[i_bad][j_bad] = State::Marked;
    }
  }

  if ((j_hole + diff) > max) {return false;}

  for (int iDiff = i_next; iDiff < max; ++iDiff){
    for (int jDiff = j_hole; jDiff < j_hole + diff; ++jDiff){
      if (s[iDiff][jDiff] == State::Marked) continue;
      s_bad[iDiff][jDiff] = State::Empty;
    }
  }    
  return (s_bad == s);
}
