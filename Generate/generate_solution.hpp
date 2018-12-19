#pragma once
#include "solution.hpp"
#include "rules.hpp"
#include <utility> // pair
#include <initializer_list>
// Generate a solution that follows some rules

Solution generate_solution(int, TreesAcross&, TreeRadius&);
bool fails_base_case(std::pair<int, int> pair, Solution s);
