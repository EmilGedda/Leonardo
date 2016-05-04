#ifndef AST_HPP
#define AST_HPP
#include "expressions/statement/statement.hpp"
#include <vector>
#include <memory>

// Forward declaration
class Context;

class AST
{

private:
  // Our AST is actually a vector of Statements
  std::vector<std::unique_ptr<Statement>> statements;

public:
  void add(std::unique_ptr<Statement> statement) {
    statements.push_back(std::move(statement));
  }

  // Execute all statements in order
  void execute(Context& ctx) {
    for(auto& s : statements)
      s->execute(ctx);
  }

};

#endif
