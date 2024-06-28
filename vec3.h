#pragma once 

#include <iostream>
#include <cmath>

/*
    vector class banani for color and postion
    basic functions like operator overloading like [], - , += , *= , /= ..
    basic function me ayennge lenght , lenght_squared
    constructor , getter
*/

class vec3 {

    double elements[3];

public:


    // Constructor
    vec3 () : elements{0, 0, 0} {}
    vec3 (double x, double y, double z) : elements{x, y, z} {}

    // getters

    double x() const {return elements[0];}
    double y() const {return elements[1];}
    double z() const {return elements[2];}

    // operator oveloading
    vec3 operator-() const { return vec3(-elements[0], -elements[1], -elements[2]); }
    double operator[](int i) const { return elements[i]; }
    double& operator[](int i) { return elements[i]; }


    vec3& operator+=(const vec3 &v) {

        elements[0] += v.x();
        elements[1] += v.y();
        elements[2] += v.z();

        return *this;
    }

    vec3& operator*=(const double t) {

        elements[0] *= t;
        elements[1] *= t;
        elements[2] *= t;
        return (*this);

    }

    vec3& operator/=(const double t) {
        return *this *= 1/t;
    }

    // length of vector
    double length_squared() const {
        return elements[0]*elements[0] + elements[1]*elements[1] + elements[2]*elements[2];
    }

    double length() const {
        return sqrt(length_squared());
    }



    /*
    Now lets name it point as we will use  it a alias 
    toh abb uske liye aur bhi operator overlaoding like +, - ,* , /, dot, cross ..
    */

  

   // outstream
   inline friend std::ostream& operator<<(std::ostream& out, const vec3& v) 
   {
        return out << v.elements[0] << ' ' << v.elements[1] << ' ' << v.elements[2];
   }

   inline friend vec3 operator+ (const vec3& v1, const vec3& v2)
   {
        return vec3( v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z() );
   }

   inline friend vec3 operator- (const vec3& v1, const vec3& v2)
   {
        return vec3(  v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z() );
   }

   inline friend vec3 operator* (const vec3& v1, const vec3& v2)
   {
        return vec3(  v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z() );
   }

   inline friend vec3 operator* (const double t, const vec3 v)
   {
        return vec3( v.elements[0] * t, v.elements[1] * t, v.elements[2] * t);
   }

   inline friend vec3 operator* (const vec3 v, const double t)
   {
        return t * v;
   }

   inline friend vec3 operator/ (const double t, const vec3 v)
   {
        return 1/t * v;
   }

   inline friend vec3 operator/ (const vec3 v, const double t)
   {
        return 1/t * v;
   }

   inline friend double dot (const vec3 v1, const vec3 v2)
   {
        return (
            v1.x() * v2.x() + 
            v1.y() * v2.y() + 
            v1.z() * v2.z()
        );
   } 

   inline friend vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
    }

    inline friend vec3 unit_vector(const vec3& v) {
        return v / v.length();
    }


};


 // Alias as Point3
   using point3 = vec3;