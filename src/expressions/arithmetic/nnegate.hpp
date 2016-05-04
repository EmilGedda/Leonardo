#ifndef NNEGATE_HPP
#define NNEGATE_HPP

#include "arithnode.hpp"
#include <memory>

/** Calculation node negating the value of the operand subtree. */
class NNegate : public ArithNode
{

private:
  // node subtree
  std::unique_ptr<ArithNode> node;

public:
  explicit NNegate(std::unique_ptr<ArithNode> node)
    : ArithNode(), node(std::move(node)) { }

  virtual int evaluate() const
  {
    return - node->evaluate();
  }

};

#endif
