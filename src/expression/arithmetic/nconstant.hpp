#ifndef NCONSTANT_HPP
#define NCONSTANT_HPP

#include "arithnode.hpp"
#include <ostream>

/** Calculation node always returning a constant value. */
class NConstant : public ArithNode
{
  /// the constant value returned
  int	value;

  public:
  /// construct a constant calculation node from a value
  explicit NConstant(int _value)
    : ArithNode(), value(_value)
  {
  }

  virtual int evaluate() const
  {
    return value;
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << value << std::endl;
  }
};

#endif
