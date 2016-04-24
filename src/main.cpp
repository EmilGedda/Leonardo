// $Id$

#include <iostream>
#include <fstream>

#include "driver.hpp"
#include "expressions/expression.hpp"
#include "turtle/turtle.hpp"
#include "writers/default.hpp"
#include "context.hpp"

int main(int argc, char *argv[])
{
  std::unique_ptr<Writer> writer(new Default());
  Context ctx(std::move(writer));

  example::Driver driver(ctx);
  bool readfile = false;

  for(int ai = 1; ai < argc; ++ai)
  {
    if (argv[ai] == std::string ("-p")) {
      driver.trace_parsing = true;
    }
    else if (argv[ai] == std::string ("-s")) {
      driver.trace_scanning = true;
    }
    else
    {
      // read a file with expressions

      std::fstream infile(argv[ai]);
      if (!infile.good())
      {
        std::cerr << "Could not open file: " << argv[ai] << std::endl;
        return 0;
      }

      //ctx.clear_expressions();
      bool result = driver.parse_stream(infile, argv[ai]);
      if (result)
      {

        auto s = ctx.ast.top();
        s->execute(ctx);
      }

      readfile = true;
    }
  }

  if (readfile) return 0;

}
