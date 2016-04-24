#ifndef STREP_HPP
#define STREP_HPP

#include "statement.hpp"
#include "../../ast.hpp"
#include "../arithmetic/arithnode.hpp"

#include <memory>
#include <string>

class STRep : public Statement {
private:
  ArithNode* count;
  AST* ast;

public:
  explicit STRep(ArithNode* count, AST* ast) : count(count), ast(ast) { }

  void execute(Context& ctx) const
  {
    int cnt = count->evaluate();
    for(int i = 0; i < cnt; i++)
      ast->execute(ctx); 
  }

};

#endif
