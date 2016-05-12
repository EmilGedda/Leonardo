
#ifndef STFORW_HPP
#define STFORW_HPP

#include "statement.hpp"
#include "../arithmetic/arithnode.hpp"
#include "../../context.hpp"

#include <memory>
#include <string>
#include <ostream>
// forward statement (FORW X.) 
// A backwards movement is simply a STForw(NNegate(node))
class STForw : public Statement
{

private:
  std::unique_ptr<ArithNode> steps;

public:
  explicit STForw(std::unique_ptr<ArithNode> steps) : steps(std::move(steps)) { }

  void execute(Context& ctx) const
  {
    ctx.turtle().forward(steps->evaluate());
  }

};

#endif
