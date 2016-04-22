#ifndef NADD_HPP
#define NADD_HPP

#include "arithnode.hpp"
#include <ostream>
/** Calculation node adding two operand nodes. */

class NAdd : public ArithNode
{
  /// left calculation operand
  ArithNode* 	left;

  /// right calculation operand
  ArithNode* 	right;

  public:
  explicit NAdd(ArithNode* _left, ArithNode* _right)
    : ArithNode(), left(_left), right(_right)
  {
  }

  virtual ~NAdd()
  {
    delete left;
    delete right;
  }

  virtual int evaluate() const
  {
    return left->evaluate() + right->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "+ add" << std::endl;
    left->print(os, depth+1);
    right->print(os, depth+1);
  }
};

#endif
