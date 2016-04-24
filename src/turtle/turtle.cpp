#include <string>
#include <memory>
#include <cmath>
#include "turtle.hpp"

#define M_PI           3.14159265358979323846

void Turtle::up() {
  pen_down = 0;
}

void Turtle::down() {
  pen_down = 1;
}

void Turtle::left(int deg) {
  rot -= deg;
}

void Turtle::right(int deg) {
  rot += deg;
}

void Turtle::forward(int steps) {
  double pre_x = pos_x;
  double pre_y = pos_y;

  pos_x += (double)steps*cos(M_PI*(double)rot/180);
  pos_y += (double)steps*sin(M_PI*(double)rot/180);

  writer->draw_line(color, pre_x, pre_y, pos_x, pos_y);
}

void Turtle::back(int steps) {
  forward(-steps);
}

void Turtle::set_color(const std::string& clr) {
  color = clr;
}
