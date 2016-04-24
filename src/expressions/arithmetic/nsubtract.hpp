#ifndef NSUBTRACT_HPP
#define NSUBTRACT_HPP

#include "arithnode.hpp"
#include <ostream>

/** Calculation node subtracting two operand nodes. */
class NSubtract : public ArithNode
{
  /// left calculation operand
  ArithNode* 	left;

  /// right calculation operand
  ArithNode* 	right;

  public:
  explicit NSubtract(ArithNode* _left, ArithNode* _right)
    : ArithNode(), left(_left), right(_right)
  {
  }

  virtual ~NSubtract()
  {
    delete left;
    delete right;
  }

  virtual int evaluate() const
  {
    return left->evaluate() - right->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "- subtract" << std::endl;
    left->print(os, depth+1);
    right->print(os, depth+1);
  }
};

#endif
