#pragma once 
#include <iostream>

/* The park class represents a park region and reqired trees*/

class Park{
public:
  Park(int n);
  Park();
  Park(char c);
  Park(char c, int n);

  int trees_required() const { return num_trees_req; }
  char char_rep() const { return rep; }

private:
  int num_trees_req;
  char rep;
};

bool operator==(const Park&, const Park&);
bool operator!=(const Park&, const Park&);

std::ostream& operator<<(std::ostream& out, const Park& m);
