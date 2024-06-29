#include "include.h"

#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"


color ray_color(const ray& r, const hittable& world){
    //return color(0, 0, 0);

    // Check if r passes the sphere - while doing the sphere thing
    hit_record rec;
    if (world.hit(r, interval(0, infinity), rec))
    {
      //  std::cerr << "Ray hit hui hai\n";
        return 0.5 * (rec.normal + color (1, 1, 1));
    }
    

    // Simple blue-white linear gradient
    vec3 unit_direction = unit_vector(r.get_direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color (1.0, 1.0, 1.0) + a * color (0.5, 0.7, 1.0);
}

int main() 
{

   hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;

    cam.render(world);
    
    return 0;

}