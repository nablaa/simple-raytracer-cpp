#ifndef COMMON_HH
#define COMMON_HH

#include "vector.hh"

struct Color {
	float r, g, b;
};

struct Ray {
	Vector3 *direction;
	Point origin;
};

struct Light {
	Point origin;
	double intensity;
};


#endif // COMMON_HH
