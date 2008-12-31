#ifndef SCENE_HH
#define SCENE_HH

#include <vector>
#include <stdexcept>
#include <limits>
#include "primitive.hh"
#include "common.hh"
#include "vector.hh"
#include "matrix.hh"

class Camera {
public:
	Camera(Point origin, Matrix3 rotation,
	       size_t width, size_t height, double factor = 1.0);

	Ray *shoot_ray(size_t i, size_t j);
	size_t get_width() const;
	size_t get_height() const;

private:
	Point origin;
	Matrix3 rotation;
	size_t w;
	size_t h;
	double factor;
	double dx;
	double dy;

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
	
	Color cast_ray(Ray *ray);
	const Primitive *find_nearest(const Ray& ray, Point& nearest_p);
	Color calculate_shading(const Primitive& primitive, bool in_shadow,
	                        const Light& l, double l_distance,
	                        const Color *refraction_color,
	                        const Color *reflection_color, double rs,
	                        const Point& hit_p);
};


#endif // SCENE_HH
