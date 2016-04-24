#ifndef AST_HPP
#define AST_HPP
#include "expressions/statement/statement.hpp"
#include <vector>

class Context;

class AST {
// TODO: std::unique_ptr
private:
  std::vector<Statement*> statements;

public:

  void add(Statement* statement) {
    statements.push_back(statement);
  }

  void execute(Context& ctx) {
    for(auto& s : statements)
      s->execute(ctx);
  }

  ~AST() {
    for(unsigned int i = 0; i < statements.size(); i++)
      delete statements[i];
    statements.clear();
  }

};

#endif
