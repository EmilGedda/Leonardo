#ifndef NADD_HPP
#define NADD_HPP

#include "arithnode.hpp"
#include <memory>

/** Node responsible for adding two operand nodes. */
class NAdd : public ArithNode
{

private:
  // left calculation operand
  std::unique_ptr<ArithNode> left;

  // right calculation operand
  std::unique_ptr<ArithNode> right;

public: 
  // Explicit default constructor wanted, we dont want any converting
  explicit NAdd(std::unique_ptr<ArithNode> left, std::unique_ptr<ArithNode> right)
    : ArithNode(), left(std::move(left)), right(std::move(right)) { }

  virtual int evaluate() const
  { 
    return left->evaluate() + right->evaluate();
  }

};

#endif
