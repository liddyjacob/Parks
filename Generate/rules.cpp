#include "rules.hpp"
#include "community.hpp"
#include <utility> //std::make_pair
#include <unordered_map>

Rule::Rule(Kind k)
  : kind(k)
{ }

TreesAcross::TreesAcross(size_t s)
  : Rule(trees_across), num(s)
{}

// Breaks the rules or not?
bool 
TreesAcross::breaks_rule(Solution s, Community& c){
  // Map 
  std::unordered_map<Park*, int> parks_trees;
  // Set up all parks with zero trees
  for (Park* p : c.get_parks()){
    parks_trees.insert({p, 0});
  }

  // Loop through an i and j variable
  for(size_t i = 0; i < c.num_rows(); ++i){
    
    // Set row/col i trees to 0
    int num_row_found = 0;
    int num_col_found = 0;
    
    for(size_t j = 0; j < c.num_cols(); ++j){
  
      if (s[i][j] == State::Tree){
        // Found a tree in row i
        num_row_found += 1;
        
        // Found a tree in this park
        Park* park_pointer = c[i][j];
        parks_trees[park_pointer] += 1;
      }

      if (s[j][i] == State::Tree){
        // Found a tree in col i
        num_col_found += 1;
      }
    }
    // Wrong number of trees in row i or col i?
    if (num_row_found != num) { return true; }
    if (num_col_found != num) { return true; }

  }

  // Wrong number of trees in at least one park?
  for (Park* p : c.get_parks()){
    if (parks_trees.at(p) != num) { return true; }
  }

  // Everything is right: rule not broken.
  return false;
}

TreeRadius::TreeRadius(size_t r)
  : Rule(tree_radius), radius(r)
{ }


bool 
TreeRadius::breaks_rule(Solution s, Community& c){
  for(int i = 0; i < c.num_rows(); ++i){ 
    for(int j = 0; j < c.num_cols(); ++j){
      if (s[i][j] == State::Tree){
        for (std::pair<int, int> near_point : within_radius(radius, std::make_pair(i, j), c.num_cols() )){
          
          int i2 = near_point.first;
          int j2 = near_point.second;

          if (s[i2][j2] == State::Tree){ return true; }
        }
      }
    }
  }

  return false;
}

// Default rulebook
RuleBook::RuleBook()
  : std::vector<Rule*>()
{ }

// Initializer rulebook
RuleBook::RuleBook(std::initializer_list<Rule*> list)
  : std::vector<Rule*>(list)
{ }


RuleBook& 
RuleBook::operator=(const RuleBook& rhs)
{
  std::vector<Rule*>::operator = (rhs);
  return *this;
}

std::vector<std::pair<int, int> > within_radius(int r, std::pair<int, int> point, int max){
  
  std::vector<std::pair<int, int> > points;

  int i = point.first;
  int j = point.second;
  std::cerr << "Checking point (" << i << ", " << j << ")\n";
  
  // di, dj: Differential i, differential j
  for (int di = -r; di <= r; ++di){
    for (int dj = -r; dj <= r; ++dj){
      if ((i + di < 0) || (j + dj < 0)) { continue; }
      if ((i + di >= max) || (j + dj >= max)) { continue; }
      if ((di == 0) && (dj == 0)){ continue; }

      std::cerr << "  Adding (" << i + di  << ", " << j + dj << ")\n";
      points.push_back(std::make_pair(i + di, j + dj)); 
    
    }
  }

  return points;
}
