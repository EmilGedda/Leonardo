#ifndef DEFAULT_HPP
#define DEFAULT_HPP

#include "../writer.hpp"

class Default final : public Writer {

public:
  void finalize() override { }
  ~Default() { }
  Default() : Writer() { }
  Default(std::ostream& output) : Writer(output) { }

  void draw_line(std::string color, double from_x,
      double from_y, double to_x, double to_y) override;
};

#endif
