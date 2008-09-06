#ifndef SCENE_HH
#define SCENE_HH

#include <vector>
#include "primitive.hh"
#include "common.hh"
#include "vector.hh"

class Camera {
public:
	Camera(Point origin, Vector3 direction,
	       size_t width, size_t height, double ratio, double fov = 45.0);

	Ray *shoot_ray(size_t i, size_t j);

private:
	Point origin;
	Vector3 direction;
	size_t w;
	size_t h;
	double ratio;
	double fov;
	Ray ray;
	Vector3 ray_v;
};


class Scene {
public:
	Scene(Camera& camera);
	void add_object(const Primitive *);
	void add_light(const Light *);
	void render();

private:
	std::vector<const Light *> lights;
	std::vector<const Primitive *> objects;
	Camera& camera;
};


#endif // SCENE_HH
