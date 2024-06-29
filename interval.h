#pragma once

#include <limits>
const double infinity = std::numeric_limits<double>::infinity();

class interval {

    public:

        double min, max;

        interval() : min(+infinity), max (-infinity) {}

        interval (double min, double max) : min (min), max (max) {}

        inline double size () { return min - max; }

        inline bool contains(double x) const { return  (min <= x && x <= max); }

        inline bool surrounds(double x) const { return  (min < x && x < max); }

        static const interval empty, universe;
};

const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval (-infinity, +infinity);