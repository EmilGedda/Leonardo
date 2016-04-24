#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "../../turtle/turtle.hpp"

class Context;

class Statement {

public:
  virtual ~Statement() { }
  virtual void execute(Context& ctx) const = 0;

};

#endif
