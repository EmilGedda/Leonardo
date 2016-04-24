#ifndef NDIVIDE_HPP
#define NDIVIDE_HPP

#include "arithnode.hpp"
#include <ostream>

/** Calculation node dividing two operand nodes. */
class NDivide : public ArithNode
{
  /// left calculation operand
  ArithNode* 	left;

  /// right calculation operand
  ArithNode* 	right;

  public:
  explicit NDivide(ArithNode* _left, ArithNode* _right)
    : ArithNode(), left(_left), right(_right)
  {
  }

  virtual ~NDivide()
  {
    delete left;
    delete right;
  }

  virtual int evaluate() const
  {
    return left->evaluate() / right->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "/ divide" << std::endl;
    left->print(os, depth+1);
    right->print(os, depth+1);
  }
};

#endif
