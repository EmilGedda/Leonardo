#include "default.hpp"
#include <ostream>
#include <iomanip>

void Default::draw_line(std::string color, double from_x, 
    double from_y, double to_x, double to_y) {

 out << color << " " << std::setprecision(4) << std::fixed
   << from_x << " " << from_y << " " << to_x  << " " << to_y << std::endl;
}

