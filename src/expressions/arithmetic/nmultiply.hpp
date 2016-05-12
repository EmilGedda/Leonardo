#ifndef NMULTIPLY_HPP
#define NMULTIPLY_HPP

#include "arithnode.hpp"
#include <memory>

/** Node multiplying two operand nodes. */
class NMultiply : public ArithNode
{

private:
  // left operand
  std::unique_ptr<ArithNode> left;

  // right operand
  std::unique_ptr<ArithNode> right;

public:
  explicit NMultiply(std::unique_ptr<ArithNode> left, std::unique_ptr<ArithNode> right)
    : ArithNode(), left(std::move(left)), right(std::move(right)) { }

  virtual int evaluate() const
  {
    return left->evaluate() * right->evaluate();
  }

};

#endif
