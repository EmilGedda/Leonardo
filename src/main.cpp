#include <fstream>
#include <cstring>

#include "driver.hpp"
#include "expressions/expression.hpp"
#include "turtle/turtle.hpp"
#include "writers/svg.hpp"
#include "writers/default.hpp"
#include "context.hpp"

int parse(std::unique_ptr<Writer> writer, bool scan, bool parse, 
    std::istream& stream, std::string name)
{
  Writer& w = *writer.get();
  Context ctx(std::move(writer));
  logo::Driver driver(ctx);
  driver.trace_parsing = parse;
  driver.trace_scanning = scan;

  bool success = driver.parse_stream(stream, name);

  if (success) {
    auto s = std::move(ctx.ast.top());
    s->execute(ctx);
    w.finalize();
  }
  return success ? 0 : 1;
}

int main(int argc, char *argv[])
{
  std::unique_ptr<Writer> writer(new SVG());
  bool trace_scanning = false;
  bool trace_parsing = false;

  for(int ai = 1; ai < argc; ++ai)
  {
    if (std::strcmp(argv[ai], "-p") == 0) {
      trace_parsing = true; //Enable debugging in bison
    }
    else if (std::strcmp(argv[ai],"-s") == 0) {
      trace_scanning = true; // Enable debugging in flex
    } else if (std::strcmp(argv[ai], "-text") == 0) {
      writer.reset(new Default()); //Change to default-text output
    }
    else
    {
      // read a file with expressions

      std::ifstream infile(argv[ai]);
      if (!infile.good())
      {
        std::cerr << "Could not open file: " << argv[ai] << std::endl;
        return 1;
      }

      // Parse with the given file
      return parse(std::move(writer), trace_scanning
            , trace_parsing, infile, argv[ai]);
    }
  }

  // If no file was supplied as parameter, simply use stdin
  return parse(std::move(writer), trace_scanning
      , trace_parsing, std::cin, "stdin");
}
