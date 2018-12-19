#pragma once
#include "matrix.hpp"
#include "state.hpp"
#include <utility>

struct Solution : public Matrix<State>{

  Solution(int n);

};

void mark_within_radius(int, std::pair<int, int>, Solution&);

void mark_row(int row, Solution& s);

void mark_col(int col, Solution& s);

std::ostream& operator<<(std::ostream& out, const Solution& s);
//class Solution : public Matrix<State>;
