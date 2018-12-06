#include "community.hpp"
#include <iostream>
#include <cstdlib> // abort

Community::Community() 
  : Matrix<Park*>(0, 0)
{}

Community::Community(int rowcols) 
  : Matrix<Park*>(rowcols, rowcols, nullptr)
{}

void 
Community::create_parks(int num_trees)
{
  char c = 'A';
  for (int i = 0; i <  num_rows(); ++i){
    Park* p = new Park(c, num_trees);
    parks.push_back(p);    
    ++c;
  }
  
  return;
}

void 
Community::set_park(int park_id, std::initializer_list<std::pair<int, int> > list){

  if (park_id >= parks.size()) {
    std::cerr << "park_id " << park_id << " out of range!\n";
    std::abort();
  }

  for (auto pair : list){
    int i = pair.first;
    int j = pair.second;

    if (i >= num_rows()) {
      std::cerr << "coordinate (" << i  << ", " << j << ") is out of range!\n";
      std::abort();
    }
    if (j >= num_cols()) {
      std::cerr << "coordinate (" << i  << ", " << j << ") is out of range!\n";
      std::abort();
    }
    (*this)[i][j] = parks[park_id];
  }

  return;
}

void 
Community::set_park(int park_id, std::vector<std::pair<int, int> > list){

  if (park_id >= parks.size()) {
    std::cerr << "park_id " << park_id << " out of range!\n";
    std::abort();
  }

  for (auto pair : list){
    int i = pair.first;
    int j = pair.second;

    if (i >= num_rows()) {
      std::cerr << "coordinate (" << i  << ", " << j << ") is out of range!\n";
      std::abort();
    }
    if (j >= num_cols()) {
      std::cerr << "coordinate (" << i  << ", " << j << ") is out of range!\n";
      std::abort();
    }
    (*this)[i][j] = parks[park_id];
  }

  return;
}

void
Community::set_rules(std::initializer_list<Rule*> list){
  book = RuleBook(list); 
}

bool
Community::is_solved_by(Solution s){
  // Iterate through the rules in the rulebook
  for (Rule* r : book){
   if (r->breaks_rule(s, parks)) { return false; }
  }
  return true;
}

Community::~Community()
{

  for (Park* p : parks){
    delete p;
  }

  /*
  for (int i = 0; i < num_rows(); ++i){
    for (int j = 0; j < num_cols(); ++j){
      if ( (*this)[i][j] ) { delete (*this)[i][j]; }
    }
  }
  */


  return;
}

