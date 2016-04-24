#ifndef NVARIABLE_HPP
#define NVARIABLE_HPP

#include "arithnode.hpp"
#include <string>
#include "../../context.hpp"
#include <ostream>
/** Calculation node adding two operand nodes. */

class NVariable : public ArithNode
{
  Context& ctx;
  std::string name;
  public:
  explicit NVariable(std::string var, Context& ctx)
    : ArithNode(), ctx(ctx), name(var) 
  {
  }

  virtual ~NVariable()
  {

  }

  virtual int evaluate() const
  {
    return ctx.get_variable(name); 
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "variable: " << name << std::endl;
  }
};

#endif
