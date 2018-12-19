#pragma once
#include <iostream>
enum class State {
  Empty,
  Marked,
  Tree,
};


std::ostream& operator<<(std::ostream& out, const State& state);
