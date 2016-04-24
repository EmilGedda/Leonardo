#ifndef STLEFT_HPP
#define STLEFT_HPP

#include "statement.hpp"
#include "../arithmetic/arithnode.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>

class STLeft : public Statement {
private:
  ArithNode* deg;

public:
  explicit STLeft(ArithNode* deg) : deg(deg) { }

  void execute(Context& ctx) const
  {
    ctx.turtle().left(deg->evaluate());
  }

};

#endif
