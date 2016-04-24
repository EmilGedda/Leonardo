#ifndef STCOLOR_HPP
#define STCOLOR_HPP

#include "statement.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>

class STColor : public Statement {
private:
  std::string color;

public:
  explicit STColor(std::string color) : color(color) { }

  void execute(Context& ctx) const
  {
    ctx.turtle().set_color(color);
  }

};

#endif
