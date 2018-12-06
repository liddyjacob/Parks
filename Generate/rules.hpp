#pragma once
/*
 *
 * Contains the TreesAcross rule and the TreeRootRadius rule
 *
 * TreesAcross: 
 * Set the numer of trees across
 * each row and column to solve the puzzle.
 * 
 *   TreesAcross(2) : 
 *      * Two trees needed in each column and row
 *
 *
 * TreeRootRadius(n):
 * Set the radius of the root of the tree.
 * Other trees will not be allowed to spawn within a 
 * square around the tree with 'radius' n
 */
#include <vector>
#include <cstdlib>
#include <initializer_list>
#include "solution.hpp"
#include "park.hpp"

using std::size_t;

struct Rule{

  enum Kind{
    trees_across,
    tree_radius
  };

  Rule(Kind k);
  Kind kind;

  virtual bool breaks_rule(Solution, std::vector<Park*>) = 0;
};

struct TreesAcross : public Rule{
  TreesAcross(size_t);
  size_t num;

  bool breaks_rule(Solution, std::vector<Park*>) override;
};

struct TreeRadius : public Rule{
  TreeRadius(size_t);
  size_t radius;

  bool breaks_rule(Solution, std::vector<Park*>) override;
};


// A collection of rules
class RuleBook : public std::vector<Rule*>{
public:
  // Default rulebook
  RuleBook();

  // Initializer rulebook
  RuleBook(std::initializer_list<Rule*>);

 //Check the rules o 
  //bool validate(Solution, );
  RuleBook& operator=(const RuleBook& rhs);
  
private:
};
