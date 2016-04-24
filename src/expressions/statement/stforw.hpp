
#ifndef STFORW_HPP
#define STFORW_HPP

#include "statement.hpp"
#include "../arithmetic/arithnode.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>

class STForw : public Statement {
private:
  ArithNode* steps;

public:
  explicit STForw(ArithNode* steps) : steps(steps) { }

  void execute(Context& ctx) const
  {
    ctx.turtle().forward(steps->evaluate());
  }

};

#endif
