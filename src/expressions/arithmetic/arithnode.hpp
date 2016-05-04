#ifndef ARITHNODE_HPP
#define ARITHNODE_HPP

/** ArithNode is the abstract base class for arithmetic nodes in the AST
 * From it the different nullary, unary and binary nodes are derived. */
class ArithNode
{

public:
  // required for virtual functions. in the derived classes the operands are
  // deleted automatically using std::unique_ptr 
  virtual ~ArithNode() { }

  // evaluate the complete arithmetic tree and return corresponding value
  virtual int	evaluate() const = 0;

};

#endif
