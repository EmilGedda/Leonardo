#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>

#include "expression.hpp"

/** Calculator context used to save the parsed expressions. This context is
 * passed along to the example::Driver class and fill during parsing via bison
 * actions. */
class Context
{
  public:

    /// type of the variable storage
    typedef std::map<std::string, int> variablemap_type;

    /// variable storage. maps variable string to ints
    variablemap_type		variables;

    /// array of unassigned expressions found by the parser. these are then
    /// outputted to the user.
    std::vector<ArithNode*>	expressions;

    /// free the saved expression trees
    ~Context()
    {
      clearExpressions();
    }

    /// free all saved expression trees
    void	clearExpressions()
    {
      for(unsigned int i = 0; i < expressions.size(); ++i)
      {
        delete expressions[i];
      }
      expressions.clear();
    }

    /// check if the given variable name exists in the storage
    bool	existsVariable(const std::string &varname) const
    {
      return variables.find(varname) != variables.end();
    }

    /// return the given variable from the storage. throws an exception if it
    /// does not exist.
    int	getVariable(const std::string &varname) const
    {
      auto vi = variables.find(varname);
      if (vi == variables.end())
        throw(std::runtime_error("Unknown variable."));
      else
        return vi->second;
    }
};

#endif 
