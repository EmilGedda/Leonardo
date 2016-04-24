#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <stack>

#include "expressions/statement/statement.hpp"
#include "turtle/turtle.hpp"
#include "ast.hpp"
/** Runtime context used to save the parsed expressions. This context is
 * passed along to the example::Driver class and fill during parsing via bison
 * actions. */
class Context
{

public:
  
  /// variable storage. maps variable string to ints
  std::map<std::string, int> variables;
  
  Turtle leonardo;

  Context(std::unique_ptr<Writer> w) : leonardo(std::move(w))
  {
    ast.push(new AST());
  }

  Turtle& turtle()
  {
    return leonardo;
  }

  /// array of unassigned expressions found by the parser. these are then
  /// outputted to the user.
  std::stack<AST*> ast;

  /// free the saved expression trees
  ~Context()
  {
    delete ast.top();
    ast.pop();
  }


  /// check if the given variable name exists in the storage
  bool variable_exists(const std::string &varname) const
  {
    return variables.find(varname) != variables.end();
  }

  /// return the given variable from the storage. throws an exception if it
  /// does not exist.
  int	get_variable(const std::string &varname) const
  {
    auto vi = variables.find(varname);
    
    if (vi == variables.end()) 
      throw(std::runtime_error("Unknown variable."));
    
    return vi->second;
  }
};

#endif 
