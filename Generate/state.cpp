#include "state.hpp"


std::ostream& operator<<(std::ostream& out, const State& state){
  if (state == State::Empty)  out << "-";
  if (state == State::Marked) out << "*";
  if (state == State::Tree)   out << "T";
  return out;
}
