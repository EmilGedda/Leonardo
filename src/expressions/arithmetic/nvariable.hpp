#ifndef NVARIABLE_HPP
#define NVARIABLE_HPP

#include "arithnode.hpp"
#include <string>
#include "../../context.hpp"

/** Node referring to a variable subtree */
class NVariable : public ArithNode
{

private:
  // the context of our variable
  Context& ctx; 

  // the name of the variable
  std::string name;

public:
  explicit NVariable(std::string var, Context& ctx)
    : ArithNode(), ctx(ctx), name(var) { }

  virtual int evaluate() const
  {
    return ctx.get_variable(name); 
  }

};

#endif
