#pragma once

#include <string>
#include <functional>
#include <compare>

namespace table {

struct Point {
    std::string name;
    double x, y, z;

    auto operator<=>(const Point&) const = default;
};


struct PointHash {
    size_t operator()(const Point& p) const {
        size_t h1 = std::hash<std::string>{}(p.name);
        size_t h2 = std::hash<double>{}(p.x);
        size_t h3 = std::hash<double>{}(p.y);
        size_t h4 = std::hash<double>{}(p.z);
        return h1 ^ (h2 << 1) ^ (h3 << 2) ^ (h4 << 3);
    }
};

}