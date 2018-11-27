#pragma once
#include "matrix.hpp"
#include "park.hpp"
#include <vector>
#include <cassert> // assert

///
/// A community is a matrix of parks.
/// A communuty determines 
class Community : public Matrix<Park*>{
public:
  
  
  Community(); 
  Community(int rowcols);
  Community(int rows, int cols);

  // 1 indicates 
  void Create_Parks();

  ~Community();

private:
  std::vector<Park*> parks;
};
