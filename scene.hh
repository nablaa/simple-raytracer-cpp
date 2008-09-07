#ifndef SCENE_HH
#define SCENE_HH

#include <vector>
#include <stdexcept>
#include <limits>
#include "primitive.hh"
#include "common.hh"
#include "vector.hh"

class Camera {
public:
	Camera(Point origin, Vector3 direction, Vector3 angle,
	       size_t width, size_t height, double ratio, double fov = 45.0);

	Ray *shoot_ray(size_t i, size_t j);
	size_t get_width() const;
	size_t get_height() const;

private:
	Point origin;
	Vector3 direction;
	Vector3 angle;
	size_t w;
	size_t h;
	double ratio;
	double fov;
	Point start;
	Vector3 x;
	Vector3 y;
	Ray ray;
	Vector3 ray_v;
};


class Scene {
public:
	Scene(Camera& camera, Color bg);
	void add_object(const Primitive *primitive);
	void add_light(const Light *light);
	void render();
	const ImageData& get_imagedata() const;

private:
	std::vector<const Light *> lights;
	std::vector<const Primitive *> objects;
	Camera& camera;
	Color bgcolor;
	ImageData image;
};


#endif // SCENE_HH
