#ifndef SCENE_HH
#define SCENE_HH

#include "common.hh"
#include "vector.hh"

class Camera {
public:
	Camera(Point origin, Vector3 direction, double fov = 45.0);

private:
	Point origin;
	Vector3 direction;
	double fov;

};


class Scene {
public:

private:
	std::vector<*Light> lights;
	std::vector<*Primitive> objects;
	Camera& camera;
};


#endif // SCENE_HH
