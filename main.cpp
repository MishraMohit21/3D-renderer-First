#include "vec3.h"
#include "color.h"

double hit_sphere(const point3& center, double radius, const ray& r)
{
    vec3 oc = center - r.get_origin();
    auto a = r.get_direction().length_squared();
    auto h = dot (r.get_direction(), oc);
    auto c = oc.length_squared() - radius * radius;

    auto discriminant = h*h - a * c;

    if (discriminant < 0){
        return -1.0;
    }
    else {
        return ((h - sqrt(discriminant)) / a);
    }
}


color ray_color(const ray& r){
    //return color(0, 0, 0);

    // Check if r passes the sphere - while doing the sphere thing
    auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
    if (t > 0)
    {
        vec3 N = unit_vector(r.at(t) - vec3(0, 0, -1));
        return 0.5 * color (N.x() + 1, N.y() + 1, N.z() + 1);
    }

    // Simple blue-white linear gradient
    vec3 unit_direction = unit_vector(r.get_direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color (1.0, 1.0, 1.0) + a * color (0.5, 0.7, 1.0);
}

int main() 
{

    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;

    const int image_height = (static_cast<int>(image_width / aspect_ratio) < 1) ? 1 : static_cast<int>(image_width / aspect_ratio) ;
    
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

            color pixel_color = ray_color(r);

            writeColor(std::cout, pixel_color);
        }
    }

    std::clog << "\r DONE.                                                              \n";
    return 0;

}