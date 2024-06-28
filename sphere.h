#pragma once

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable
{

public:
    sphere (const point3& cen, const double& rad) : center(cen), radius(fmax(0, radius)) {}

    bool hit(const ray& r, double tmin, double tmax, hit_record& rec) const override
    {
        vec3 oc = center - r.get_origin();
        auto a = r.get_direction().length_squared();
        auto h = dot (r.get_direction(), oc);
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = h*h - a * c;

        if (discriminant < 0)
        {
            return false;
        }

        auto sqrt_dis = sqrt(discriminant);

        // Find the nearest root that lies in acceptable range
        auto root = (h - sqrt_dis) / a;
        if (root <= tmin || root >= tmax)
        {
            root = (h + sqrt_dis) / a;
            if (root <= tmin || root >= tmax)
            {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        rec.normal = (rec.p - center) / radius;

        return true;
    }

private:

    point3 center;
    double radius;

};