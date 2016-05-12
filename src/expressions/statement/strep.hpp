#ifndef STREP_HPP
#define STREP_HPP

#include "statement.hpp"
#include "../../ast.hpp"
#include "../arithmetic/arithnode.hpp"

#include <memory>

// A REP Command. The Parser (bison) handles the quote-stuff in the grammar
class STRep : public Statement
{

private:
  
  std::unique_ptr<ArithNode> count;

  // A collection of statements (AST) which the REP should run.
  std::unique_ptr<AST> ast;

public:
  explicit STRep(std::unique_ptr<ArithNode> count, std::unique_ptr<AST> ast) 
    : count(std::move(count)), ast(std::move(ast)) { }

  void execute(Context& ctx) const
  {
    int cnt = count->evaluate();
    for(int i = 0; i < cnt; i++)
      ast->execute(ctx); 
  }

};

#endif
