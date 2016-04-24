#ifndef STASSIGNMENT_HPP
#define STASSIGNMENT_HPP

#include "statement.hpp"
#include "../arithmetic/arithnode.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>

class STAssignment : public Statement {
private:
  std::string variable;
  std::unique_ptr<ArithNode> arith;

public:
  explicit STAssignment(std::string var, std::unique_ptr<ArithNode> arith)
    : variable(var), arith(std::move(arith)) { }

  virtual ~STAssignment() 
  {

  }

  virtual void execute(Context& ctx) const
  {
    ctx.variables[variable] = arith->evaluate();
  }

};

#endif
