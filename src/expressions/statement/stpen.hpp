#ifndef STPEN_HPP
#define STPEN_HPP

#include "statement.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>

// a pen status change statement. UP -> state == 0, DOWN -> state == 1
class STPen : public Statement {
private:
  int pen_down;

public:
  explicit STPen(int state) : pen_down(state) { }

  void execute(Context& ctx) const
  {
    pen_down ? ctx.turtle().down() : ctx.turtle().up();
  }

};

#endif
