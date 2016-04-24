#ifndef SVG_HPP
#define SVG_HPP

#include "../writer.hpp"

class SVG final : public Writer {

private:
  int padding;
  int min_x = 0;
  int min_y = 0;
  int max_x = 0;
  int max_y = 0;

public:
  ~SVG() { }
  SVG(int padding = 0) : Writer(), padding(padding) {}
  SVG(std::ostream& output, int padding = 0)
    : Writer(output), padding(padding) {}

  void draw_line(std::string color, double from_x,
      double from_y, double to_x, double to_y) override;
};

#endif
