#include "primitive.hh"


Material::Material(Color color_, double ref_index_, bool refractive_)
: color(color_), ref_index(ref_index_), refractive(refractive_)
{
}

bool Material::is_refractive() const
{
	return refractive;
}

double Material::get_ref_index() const
{
	return ref_index;
}

const Color& Material::get_color() const
{
	return color;
}


Sphere::Sphere(const Material& material_, Point origin, double radius)
: material(material_), location(origin), rad(radius)
{
}

Sphere::~Sphere()
{
}

bool Sphere::intersects(const Ray& ray, Point& point) const
{
	Vector3 v = ray.origin - location;
	double disc = pow(dot(v, *ray.direction), 2) - (dot(v, v) - rad * rad);
	if (disc < 0) {
		return false;
	}
	double t1 = -dot(v, *ray.direction) + sqrt(disc);
	double t2 = -dot(v, *ray.direction) - sqrt(disc);
	if (t1 < 0 || t2 < 0) {
		return false;
	}
	
	double t = t1 < t2 ? t1 : t2;
	// ray.direction is a unit vector
	point.x = ray.origin.x + t * ray.direction->get_x();
	point.y = ray.origin.y + t * ray.direction->get_y();
	point.z = ray.origin.z + t * ray.direction->get_z();

	return true;
}

const Point& Sphere::get_location() const
{
	return location;
}


Plane::Plane(const Material& material_, Point origin_, Vector3 normal_)
: material(material_), location(origin_)
{
	normal = normal_.normalize();


}

Plane::~Plane()
{
}

bool Plane::intersects(const Ray& ray, Point& point) const
{

}

const Point& Plane::get_location() const
{
	return location;
}

