#include <fstream>
#include <sstream>

#include "driver.hpp"
#include "scanner.hpp"

namespace logo {

Driver::Driver(class Context& ctx)
    : trace_scanning(false),
      trace_parsing(false),
      ctx(ctx)
{
}

bool Driver::parse_stream(std::istream& in, const std::string& sname)
{
  streamname = sname;

  Scanner scanner(&in);
  scanner.set_debug(trace_scanning);
  this->lexer = &scanner;

  Parser parser(*this);
  parser.set_debug_level(trace_parsing);
  return (parser.parse() == 0);
}


void Driver::error(const class location& l,
		   const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}

}
