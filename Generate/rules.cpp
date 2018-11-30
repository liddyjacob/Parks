#include "rules.hpp"

Rule::Rule(Kind k)
  : kind(k)
{ }

TreesAcross::TreesAcross(size_t s)
  : Rule(trees_across), num(s)
{}

