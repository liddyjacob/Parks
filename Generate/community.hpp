#pragma once
#include "matrix.hpp"
#include "park.hpp"

///
/// A community is a matrix of parks.

class Community : public Matrix<Park*>{
public:
  
  Community() 
    : Matrix<Park*>(0, 0)
  {}

  Community(int rows, int cols) 
    : Matrix<Park*>(rows, cols, nullptr)
  {}


};
