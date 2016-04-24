#ifndef TURTLE_HPP
#define TURTLE_HPP

#include <string>
#include <memory>
#include "../writer.hpp"

class Turtle final {

private:
  double pos_x  = 0;
  double pos_y  = 0;
  int rot       = 0;
  std::string color = "#0000FF";
  int pen_down  = 0;
  std::unique_ptr<Writer> writer;

public:
  Turtle(std::unique_ptr<Writer> w) : writer(std::move(w)) {};

  void up();
  void down();
  void left(int deg);
  void right(int deg);
  void forward(int steps);
  void back(int steps);

  void set_color(const std::string& color);

};

#endif
