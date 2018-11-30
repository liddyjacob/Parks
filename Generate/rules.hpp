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

using std::size_t;

struct Rule{


  enum Kind{
    trees_across,
    tree_root_radius
  };

  Rule(Kind k);
  Kind kind;
};

struct TreesAcross : public Rule{
  TreesAcross(size_t);
  size_t num;
};

struct TreeRootRadius : public Rule{
  TreeRootRadius(size_t);
};

// A collection of rules
class RuleBook : public std::vector<Rule*>{

};
