#pragma once
#include "matrix.hpp"
#include "park.hpp"
#include "solution.hpp"
#include "rules.hpp"
#include <vector>
#include <utility>
#include <cassert> // assert
#include <initializer_list>

///
/// A community is a matrix of parks.
/// A communuty determines 
class Community : public Matrix<Park*>{
public:
  
  Community(); 
  Community(int rowcols);

  void create_parks(int trees = 1);

  void set_park(int, std::initializer_list<std::pair<int, int> >);
  void set_park(int, std::vector<std::pair<int, int> >);

  void set_rules(std::initializer_list<Rule*>);

  bool is_solved_by(Solution);

  ~Community();

private:
  std::vector<Park*> parks;
  RuleBook book;
};
