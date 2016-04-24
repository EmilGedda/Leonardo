#ifndef NNEGATE_HPP
#define NNEGATE_HPP

#include "arithnode.hpp"
#include <ostream>

/** Calculation node negating the value of the operand subtree. */
class NNegate : public ArithNode
{

private:
  /// calculation subtree
  ArithNode* 	node;

public:
  explicit NNegate(ArithNode* _node)
    : ArithNode(), node(_node)
  {
  }

  virtual ~NNegate()
  {
    delete node;
  }

  virtual int evaluate() const
  {
    return - node->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "- negate" << std::endl;
    node->print(os, depth+1);
  }
};

#endif
