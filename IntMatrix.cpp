#include "IntMatrix.h"
#include <iostream>
void IntMatrix::add_col(size_t last_col, int x)
{
  if (last_col == 0)
  {
    IntArray tmp = IntArray(x);
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        tmp.add(get(i * cols + j));
      }
      if (i != rows - 1) tmp.add(x);
    }
    data = tmp;
  }
  else
  {
    IntArray tmp = IntArray(get(0));
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < last_col; ++j)
      {
        if (i + j != 0) tmp.add(get(i * cols + j));
      }
      tmp.add(x);
      for (size_t j = last_col; j < cols; ++j)
      {
        tmp.add(get(i * cols + j));
      }
    }
    data = tmp;
  }
  cols++;
}
void IntMatrix::add_row(size_t last_row, int x)
{
  if (last_row == 0)
  {
    IntArray tmp = IntArray(x);
    for (size_t i = 0; i < cols; ++i)
    {
      tmp.add(x);
    }
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        tmp.add(get(i * cols + j));
      }
    }
    data = tmp;
  }
  else
  {
    IntArray tmp = IntArray(get(0));
    for (size_t i = 0; i < last_row; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if (i + j != 0) tmp.add(get(i * cols + j));
      }
    }
    for (size_t i = 0; i < cols; ++i)
    {
      tmp.add(x);
    }
    for (size_t i = last_row; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        tmp.add(get(i * cols + j));
      }
    }
    data = tmp;
  }
  rows++;
}
void IntMatrix::expand(size_t last_row, size_t last_col)
{
  add_row(last_row, 0);
  add_col(last_col, 0);
}

void IntMatrix::fill(int x)
{
  IntArray tmp = IntArray(data.get(0));
  for (size_t i = 0; i < size(); ++i)
  {
    tmp.add(data.get(i));
  }
  tmp.add(x);
  data = tmp;
}
size_t IntMatrix::size() const noexcept
{
  return rows*cols;
}
int IntMatrix::get(size_t id) const noexcept
{
  return data.get(id);
}
void IntMatrix::show() const noexcept {
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      std::cout << get(i*cols + j) << " ";
    }
    std::cout << "\n";
  }
}

IntMatrix::IntMatrix(size_t r, size_t c, int first_elem): rows(1), cols(1), data(IntArray(first_elem))
{
  rows = r;
  cols = c;
}
IntMatrix::~IntMatrix() {}
IntMatrix &IntMatrix::operator=(const IntMatrix &rhs) {
  IntArray tmp = IntArray(rhs.get(0));
  for (size_t i = 1; i < rhs.size(); ++i)
  {
    tmp.add(rhs.get(i));
  }
  data = tmp;
  rows = rhs.rows;
  cols = rhs.cols;
  return *this;
}


