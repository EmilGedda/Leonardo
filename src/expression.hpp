// $Id$
/** \file expression.h Implements an example calculator class group. */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <cmath>

/** ArithNode is the abstract base class for calculation nodes. From it the
 * different nullary, unary and binary nodes are derived. */
class ArithNode
{
  public:
    /// required for virtual functions. in the derived classes the operands are
    /// deleted.
    virtual ~ArithNode()
    {
    }

    /// evaluate the complete calculation tree and return the floating point
    /// result value
    virtual int	evaluate() const = 0;

    /// output the calculation tree to the given stream. tries to format the
    /// output to make tree levels visible.
    virtual void	print(std::ostream &os, unsigned int depth=0) const = 0;

    /// helper function for print() which makes the indention string
    static inline std::string indent(unsigned int d)
    {
      return std::string(d * 2, ' ');
    }
};

/** Calculation node always returning a constant value. */
class NConstant : public ArithNode
{
  /// the constant value returned
  int	value;

  public:
  /// construct a constant calculation node from a value
  explicit NConstant(int _value)
    : ArithNode(), value(_value)
  {
  }

  virtual int evaluate() const
  {
    return value;
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << value << std::endl;
  }
};

/** Calculation node negating the value of the operand subtree. */
class NNegate : public ArithNode
{
  /// calculation subtree
  ArithNode* 	node;

  public:
  explicit NNegate(ArithNode* _node)
    : ArithNode(), node(_node)
  {
  }

  virtual ~NNegate()
  {
    delete node;
  }

  virtual int evaluate() const
  {
    return - node->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "- negate" << std::endl;
    node->print(os, depth+1);
  }
};

/** Calculation node adding two operand nodes. */
class NAdd : public ArithNode
{
  /// left calculation operand
  ArithNode* 	left;

  /// right calculation operand
  ArithNode* 	right;

  public:
  explicit NAdd(ArithNode* _left, ArithNode* _right)
    : ArithNode(), left(_left), right(_right)
  {
  }

  virtual ~NAdd()
  {
    delete left;
    delete right;
  }

  virtual int evaluate() const
  {
    return left->evaluate() + right->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "+ add" << std::endl;
    left->print(os, depth+1);
    right->print(os, depth+1);
  }
};

/** Calculation node subtracting two operand nodes. */
class NSubtract : public ArithNode
{
  /// left calculation operand
  ArithNode* 	left;

  /// right calculation operand
  ArithNode* 	right;

  public:
  explicit NSubtract(ArithNode* _left, ArithNode* _right)
    : ArithNode(), left(_left), right(_right)
  {
  }

  virtual ~NSubtract()
  {
    delete left;
    delete right;
  }

  virtual int evaluate() const
  {
    return left->evaluate() - right->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "- subtract" << std::endl;
    left->print(os, depth+1);
    right->print(os, depth+1);
  }
};

/** Calculation node multiplying two operand nodes. */
class NMultiply : public ArithNode
{
  /// left calculation operand
  ArithNode* 	left;

  /// right calculation operand
  ArithNode* 	right;

  public:
  explicit NMultiply(ArithNode* _left, ArithNode* _right)
    : ArithNode(), left(_left), right(_right)
  {
  }

  virtual ~NMultiply()
  {
    delete left;
    delete right;
  }

  virtual int evaluate() const
  {
    return left->evaluate() * right->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "* multiply" << std::endl;
    left->print(os, depth+1);
    right->print(os, depth+1);
  }
};

/** Calculation node dividing two operand nodes. */
class NDivide : public ArithNode
{
  /// left calculation operand
  ArithNode* 	left;

  /// right calculation operand
  ArithNode* 	right;

  public:
  explicit NDivide(ArithNode* _left, ArithNode* _right)
    : ArithNode(), left(_left), right(_right)
  {
  }

  virtual ~NDivide()
  {
    delete left;
    delete right;
  }

  virtual int evaluate() const
  {
    return left->evaluate() / right->evaluate();
  }

  virtual void print(std::ostream &os, unsigned int depth) const
  {
    os << indent(depth) << "/ divide" << std::endl;
    left->print(os, depth+1);
    right->print(os, depth+1);
  }
};

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

#endif // EXPRESSION_H
