#ifndef INTMATRIX_H
#define INTMATRIX_H
#include "IntArray.h"
#include <iostream>
#include <cstddef>
struct IntMatrix
{
  size_t rows;
  size_t cols;
  IntArray data;

  void fill(int x);
  size_t size() const noexcept;
  int get(size_t id) const noexcept;
  void show() const noexcept;

  void add_row(size_t last_row, int x);
  void add_col(size_t last_col, int x);
  void expand(size_t last_row, size_t last_col);

  IntMatrix(size_t r, size_t c, int first_elem);
  ~IntMatrix();
  IntMatrix & operator=(const IntMatrix & rhs);
};
#endif
