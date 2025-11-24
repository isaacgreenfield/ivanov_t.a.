#include "IntMatrix.h"
#include <iostream>
#include <cstddef>
int main()
{
  IntMatrix matrix(3, 3, 1);
  IntArray newData(1);
  newData.add(2);
  newData.add(3);
  newData.add(4);
  newData.add(5);
  newData.add(6);
  newData.add(7);
  newData.add(8);
  newData.add(9);
  matrix = IntMatrix(3, 3, 1);
  matrix.data = newData;
  int x, y, z;

  while (std::cin >> x)
  {
    if (!(std::cin >> y >> z))
    {
      if (std::cin.eof())
      {
        return 3;
      }
        return 1;
    }
    try
    {
      if (x == 1)
      {
        if (y > matrix.rows)
        {
          return 1;
        }
        matrix.add_row(y, z);
        matrix.show();
      }
      else
      {
        if (y > matrix.rows || z > matrix.cols)
        {
          return 1;
        }
        matrix.expand(y, z);
        matrix.show();
      }
    }
    catch (...)
    {
      return 2;
    }
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    return 1;
  }
  matrix.show();

  return 0;
}


