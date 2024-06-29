#include "include.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"


color ray_color(const ray& r, const hittable& world){
    //return color(0, 0, 0);

    // Check if r passes the sphere - while doing the sphere thing
    hit_record rec;
    if (world.hit(r, interval(0, infinity), rec))
    {
        std::cerr << "Ray hit hui hai\n";
        return 0.5 * (rec.normal + color (1, 1, 1));
    }
    

    // Simple blue-white linear gradient
    vec3 unit_direction = unit_vector(r.get_direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color (1.0, 1.0, 1.0) + a * color (0.5, 0.7, 1.0);
}

int main() 
{

    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 1200;

    const int image_height = (static_cast<int>(image_width / aspect_ratio) < 1) ? 1 : static_cast<int>(image_width / aspect_ratio) ;
    

    hittable_list world;

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // ViewPort Camera

    auto focal_len = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto camera_center = point3(0, 0, 0); 

    // viewport vector calculate karne hai
    auto viewport_u = vec3 (viewport_width, 0, 0);
    auto viewport_v = vec3 (0, -viewport_height, 0);

    //pixel gap
    auto pixel_gap_u = viewport_u / (image_width);
    auto pixel_gap_v = viewport_v / (image_height);

    // Location of upper left pixel
    auto viewport_upper_left = camera_center 
                                - vec3(0, 0, focal_len) - viewport_u / 2 - viewport_v / 2;
    auto pixel100_loc = viewport_upper_left + 0.5 * (pixel_gap_u + pixel_gap_v);

    // Render
    
    std::cout << "P3\n" << image_width << " " << image_height << "\n256\n";

    for (int j = 0; j < image_height; ++j) 
    {
        std::clog << "\rScanning Line " << j << " of " << image_height << " lines" << std::flush;
        for (int i = 0; i < image_width; ++i) 
        {
            
            auto pixel_center = pixel100_loc + ( i * pixel_gap_u) + (j *  pixel_gap_v);
            auto ray_direction = pixel_center - camera_center;

            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, world);
            
            writeColor(std::cout, pixel_color);
        }
    }

    std::clog << "\r DONE.                                                              \n";
    return 0;

}