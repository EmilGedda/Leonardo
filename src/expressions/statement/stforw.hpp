
#ifndef STFORW_HPP
#define STFORW_HPP

#include "statement.hpp"
#include "../arithmetic/arithnode.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>

class STForw : public Statement {
private:
  int steps;

public:
  explicit STForw(int steps) : steps(steps) { }

  void execute(Context& ctx) const
  {
    ctx.turtle().forward(steps);
  }

};

#endif
