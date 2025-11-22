#ifndef INTMATRIX_H
#define INTMATRIX_H
#include "IntArray.h"
struct IntMatrix
{
  size_t rows;
  size_t cols;
  IntArray data;

  void fill(int i);
  size_t size() const noexcept;
  int get(size_t id) const noexcept;

  bool add_row(size_t last_row, int x);
  bool add_col(size_t last_col, int x);
  bool expand(size_t last_row, size_t last_col)

  IntMatrix(size_t r, size_t c);
  ~IntMatrix();
};
#endif
