#include "scene.hh"

Camera::Camera(Point origin_, Vector3 direction_,
               size_t width, size_t height, double ratio_, double fov_)
: origin(origin_), direction(direction_), w(width), h(height), ratio(ratio_), fov(fov_)
{

}

Ray *Camera::shoot_ray(size_t i, size_t j)
{

}

