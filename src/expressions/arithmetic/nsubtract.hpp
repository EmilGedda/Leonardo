#ifndef NSUBTRACT_HPP
#define NSUBTRACT_HPP

#include "arithnode.hpp"
#include <memory>

/** Node subtracting two operand nodes. */
class NSubtract : public ArithNode
{

private:
  // left operand
  std::unique_ptr<ArithNode> left;

  // right operand
  std::unique_ptr<ArithNode> right;

public:
  explicit NSubtract(std::unique_ptr<ArithNode> left, std::unique_ptr<ArithNode> right)
    : ArithNode(), left(std::move(left)), right(std::move(right)) { }

  virtual int evaluate() const
  {
    return left->evaluate() - right->evaluate();
  }

};

#endif
