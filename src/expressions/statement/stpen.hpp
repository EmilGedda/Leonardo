#ifndef STPEN_HPP
#define STPEN_HPP

#include "statement.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>

class STPen : public Statement {
private:
  int state;

public:
  explicit STPen(int state) : state(state) { }

  void execute(Context& ctx) const
  {
    state ? ctx.turtle().up() : ctx.turtle().down();
  }

};

#endif
