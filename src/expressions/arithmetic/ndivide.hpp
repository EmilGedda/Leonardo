#ifndef NDIVIDE_HPP
#define NDIVIDE_HPP

#include "arithnode.hpp"
#include <memory>

/** Node dividing two operand nodes. */
class NDivide : public ArithNode
{

private:
  // nomenator
  std::unique_ptr<ArithNode> left;

  // denomenator
  std::unique_ptr<ArithNode> right;

public:
  explicit NDivide(std::unique_ptr<ArithNode> left, std::unique_ptr<ArithNode> right)
    : ArithNode(), left(std::move(left)), right(std::move(right)) { }

  virtual int evaluate() const
  {
    return left->evaluate() / right->evaluate();
  }

};

#endif
