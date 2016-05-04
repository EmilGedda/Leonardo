#ifndef STLEFT_HPP
#define STLEFT_HPP

#include "statement.hpp"
#include "../arithmetic/arithnode.hpp"
#include "../../context.hpp"

#include <memory>

// A LEFT statement. A right statement is simulated using a negative deg param
class STLeft : public Statement 
{

private:
  std::unique_ptr<ArithNode> deg;

public:
  explicit STLeft(std::unique_ptr<ArithNode> deg) : deg(std::move(deg)) { }

  void execute(Context& ctx) const
  {
    ctx.turtle().left(deg->evaluate());
  }

};

#endif
