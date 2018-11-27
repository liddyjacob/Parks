#include "community.hpp"

Community::Community() 
  : Matrix<Park*>(0, 0)
{}

Community::Community(int rows, int cols) 
  : Matrix<Park*>(rows, cols, nullptr)
{}


Community::Community(int rowcols) 
  : Matrix<Park*>(rowcols, rowcols, nullptr)
{}

void 
Community::Create_Parks()
{
  return;
}

Community::~Community()
{
  for (int i = 0; i < num_rows(); ++i){
    for (int j = 0; j < num_cols(); ++j){
      if ( (*this)[i][j] ) { delete (*this)[i][j]; }
    }
  }

  return;
}

