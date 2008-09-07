#ifndef PRIMITIVE_HH
#define PRIMITIVE_HH

#include <cmath>
#include <stdexcept>
#include "vector.hh"
#include "common.hh"

class Material {
public:
	Material(Color color, double refraction_index = 1.0, bool refractive = false);
	bool is_refractive() const;
	double get_ref_index() const;
	const Color& get_color() const;

private:
	Color color;
	double ref_index;
	bool refractive;
};


class Primitive {
public:
	virtual ~Primitive() {};
	virtual bool intersects(const Ray& ray, Point& point) const = 0;
	virtual const Point& get_location() const = 0;
	virtual const Material& get_material() const = 0;
};


class Sphere : public Primitive {
public:
	Sphere(const Material& material, Point origin, double radius);
	~Sphere();
	bool intersects(const Ray& ray, Point& point) const;
	const Point& get_location() const;
	const Material& get_material() const;

private:
	const Material& material;
	Point location;
	double rad;
};


class Plane : public Primitive {
public:
	Plane(const Material& material, Point origin, Vector3 normal);
	~Plane();
	bool intersects(const Ray& ray, Point& point) const;
	const Point& get_location() const;
	const Material& get_material() const;

private:
	const Material& material;
	Point location;
	Vector3 normal;

};


#endif // PRIMITIVE_HH
