#ifndef NCONSTANT_HPP
#define NCONSTANT_HPP

#include "arithnode.hpp"
#include <ostream>

/** Node always returning a constant value. */
class NConstant : public ArithNode
{

private:
  // the constant value returned
  int	value;

public:
  // construct a constant calculation node from a value
  explicit NConstant(int value)
    : ArithNode(), value(value) { }

  virtual int evaluate() const
  {
    return value;
  }

};

#endif
