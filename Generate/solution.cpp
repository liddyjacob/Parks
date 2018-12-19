#include "solution.hpp"
#include "utilities.hpp"
Solution::Solution(int n) 
  : Matrix<State>(n, n, State::Empty)
{}

std::ostream& operator<<(std::ostream& out, const Solution& s){
  for (int i = 0; i < s.num_rows(); ++i){

    for (int j = 0; j < s.num_cols(); ++j){
      out << s[i][j] << ' ';
    }
    out << '\n';
  }
  return out;
}

void mark_within_radius(int radius, std::pair<int, int> pair, Solution& s){
  for (auto p : within_radius(radius, pair, s.num_cols())){
    int i = p.first;
    int j = p.second;
    s[i][j] = State::Marked;
  }
}

void mark_row(int row, Solution& s){
  for (int j = 0; j < s.num_cols(); ++j){
    if (s[row][j] != State::Tree) s[row][j] = State::Marked;
  }
}

void mark_col(int col, Solution& s){
  for (int i = 0; i < s.num_rows(); ++i){
    if (s[i][col] != State::Tree) s[i][col] = State::Marked;
  }
}

