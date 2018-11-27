#include "park.hpp"

Park::Park(int n)
  : rep('?'), num_trees_req(n)
{ }

Park::Park()
  : rep('?'), num_trees_req(1)
{ }

Park::Park(char c)
  : rep(c), num_trees_req(1)
{ }

Park::Park(char c, int n)
  : rep(c), num_trees_req(n)
{ }

bool operator==(const Park& p1, const Park& p2){
  return (&p1) == (&p2);
}

bool operator!=(const Park& p1, const Park& p2){
  return (&p1) != (&p2);
}


std::ostream& operator<<(std::ostream& out, const Park& m)
{
  out << "Park at location " << &m << '\n';
}

