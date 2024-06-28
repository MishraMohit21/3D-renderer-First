#pragma once

#include "vec3.h"

class ray {

public:

    ray() {}
    ray(const point3 org, const vec3 dir) : origin(org), direction(dir) {}

    const point3& get_origin() const { return origin; }
    const vec3& get_direction() const { return direction; }

    point3 at(double t) const{
        return origin + t * direction;
    }

private:

    point3 origin;
    vec3 direction;

};