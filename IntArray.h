#ifndef INTARRAY_H
#define INTARRAY_H
struct IntArray
{
  int * a;
  size_t k;

  void add(int i);
  int at(size_t id) const;
  int get(size_t id) const noexcept;
  size_t size() const noexcept;
  int last() const noexcept;

  IntArray(int i);
  ~IntArray();
};
#endif
