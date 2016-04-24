#ifndef STFORW_HPP
#define STFORW_HPP

#include "statement.hpp"
#include "../arithmetic/arithnode.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>

class STLeft : public Statement {
private:
  int deg;

public:
  explicit STLeft(int deg) : deg(deg) { }

  void execute(Context& ctx) const
  {
    ctx.turtle().left(deg);
  }

};

#endif
