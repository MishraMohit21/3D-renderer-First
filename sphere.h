#pragma once

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{

public:
    sphere (const point3& cen, const double& rad) : center(cen), radius(fmax(0, radius)) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override
    {
        vec3 oc = center - r.get_origin();
        auto a = r.get_direction().length_squared();
        auto h = dot(r.get_direction(), oc);
        auto c = (oc.length_squared() - radius*radius);

        auto discriminant = h*h - a*c;
        if (discriminant < 0)
            return false;

        auto sqrtd = sqrt(discriminant);
        
        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);


        return true;
    }
      

private:

    point3 center;
    double radius;

};