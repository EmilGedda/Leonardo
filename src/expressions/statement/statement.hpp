#ifndef STATEMENT_HPP
#define STATEMENT_HPP

// forward declaration
class Context;

// abstract base class
class Statement
{

public:
  virtual ~Statement() { }
  virtual void execute(Context& ctx) const = 0;

};

#endif
