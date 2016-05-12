#include "svg.hpp"
#include <ostream>
#include <string>
#include <algorithm>
#include <iomanip>

void SVG::draw_line(std::string color, double from_x, 
    double from_y, double to_x, double to_y) {
  min_x = std::min(min_x, std::min(from_x, to_x));
  min_y = std::min(min_y, std::min(from_y, to_y));

  max_x = std::max(max_x, std::max(from_x, to_x));
  max_y = std::max(max_y, std::max(from_y, to_y));

  lines.push_back("<line x1=\"" + std::to_string(from_x*45) + "\""
                      + " y1=\"" + std::to_string(from_y*45) + "\""
                      + " x2=\"" + std::to_string(to_x*45) + "\""
                      + " y2=\"" + std::to_string(to_y*45) + "\""
                      + " style=\"stroke:" + color + "\" />");

}

void SVG::init() {
}

void SVG::finalize() {
  out << std::setprecision(10) << "<svg width=\"20cm\" height=\"20cm\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"" + std::to_string(min_x*46-5) + " " + std::to_string(max_y*-46) + " " 
        + std::to_string((max_x - min_x)*46+5) + " " + std::to_string((max_y - min_y)*46) + "\">";
  out << std::endl << "    <g transform=\"scale(1,-1)\">" << std::endl;
  for(auto& s : lines)
    out << "        " << s << std::endl;

  out << "    </g>" << std::endl;
  out << "</svg>" << std::endl;
}

