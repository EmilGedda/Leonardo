#ifndef NMULTIPLY_HPP
#define NMULTIPLY_HPP

#include "arithnode.hpp"

/** Calculation node multiplying two operand nodes. */
class NMultiply : public ArithNode
{
  /// left calculation operand
  ArithNode* 	left;

  /// right calculation operand
  ArithNode* 	right;

  public:
  explicit NMultiply(ArithNode* _left, ArithNode* _right)
    : ArithNode(), left(_left), right(_right)
  {
  }

  virtual ~NMultiply()
  {
    delete left;
    delete right;
  }

  virtual int evaluate() const
  {
    return left->evaluate() * right->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "* multiply" << std::endl;
    left->print(os, depth+1);
    right->print(os, depth+1);
  }
};

#endif
