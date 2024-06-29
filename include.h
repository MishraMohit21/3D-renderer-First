#pragma once

#include <cmath>
#include <iostream>
#include <memory>


// C++ Std Usings

using std::make_shared;
using std::shared_ptr;
using std::sqrt;

// Constants


const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common Headers

#include "interval.h"
#include "color.h"
#include "ray.h"
#include "vec3.h"