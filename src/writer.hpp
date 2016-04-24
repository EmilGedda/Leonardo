#ifndef WRITER_HPP
#define WRITER_HPP

#include <iostream>
#include <string>

class Writer {

protected:
  std::ostream& out;

public:
  Writer(std::ostream& output = std::cout) : out(output) {}
  virtual ~Writer() {}
  virtual void draw_line(std::string color, double from_x, 
      double from_y, double to_x, double to_y) = 0;

};

#endif
