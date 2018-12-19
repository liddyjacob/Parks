#include "utilities.hpp"
#include <iostream>

std::vector<std::pair<int, int> > within_radius(int r, std::pair<int, int> point, int max){
  
  std::vector<std::pair<int, int> > points;

  int i = point.first;
  int j = point.second;
  
  // di, dj: Differential i, differential j
  for (int di = -r; di <= r; ++di){
    for (int dj = -r; dj <= r; ++dj){
      if ((i + di < 0) || (j + dj < 0)) { continue; }
      if ((i + di >= max) || (j + dj >= max)) { continue; }
      if ((di == 0) && (dj == 0)){ continue; }

      points.push_back(std::make_pair(i + di, j + dj)); 
    
    }
  }

  return points;
}
