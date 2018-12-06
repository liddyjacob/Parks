#include "rules.hpp"

Rule::Rule(Kind k)
  : kind(k)
{ }

TreesAcross::TreesAcross(size_t s)
  : Rule(trees_across), num(s)
{}

bool 
TreesAcross::breaks_rule(Solution, std::vector<Park*>){
  return false;
}

TreeRadius::TreeRadius(size_t r)
  : Rule(tree_radius), radius(r)
{ }

bool 
TreeRadius::breaks_rule(Solution, std::vector<Park*>){
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
