#ifndef SVG_HPP
#define SVG_HPP

#include "../writer.hpp"
#include <vector>

class SVG final : public Writer {

private:
  int padding;
  double min_x = 0;
  double min_y = 0;
  double max_x = 0;
  double max_y = 0;

  std::vector<std::string> lines;

  void init();
  std::string to_str(double val);
public:

  ~SVG() { }
  SVG(int padding = 0) : Writer(), padding(padding) { init(); }
  SVG(std::ostream& output, int padding = 0)
    : Writer(output), padding(padding) { init(); }

  void finalize() override;
  void draw_line(std::string color, double from_x,
      double from_y, double to_x, double to_y) override;
};

#endif
