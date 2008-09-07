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
	if (ray.direction->length() < 0.999 || ray.direction->length() > 1.001) {
		throw std::logic_error("ray direction must be unit vector");
	}

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

const Material& Sphere::get_material() const
{
	return material;
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
	double d = dot(Vector3(location), normal);
	double x1 = ray.origin.x;
	double y1 = ray.origin.y;
	double z1 = ray.origin.z;
	double x2 = ray.origin.x + ray.direction->get_x();
	double y2 = ray.origin.y + ray.direction->get_y();
	double z2 = ray.origin.z + ray.direction->get_z();
	double a = normal.get_x();
	double b = normal.get_y();
	double c = normal.get_z();
	double nume = d - a * x1 - b * y1 - c * z1;
	double denom = a * (x2 - x1) + b * (y2 - y1) + c * (z2 - z1);

	if (denom > -0.001 && denom < 0.001) {
		return false;
	}

	double t = nume / denom;
	if (t < 0) {
		return false;
	}
	point.x = ray.origin.x + (x2 - ray.origin.x) * t;
	point.y = ray.origin.y + (y2 - ray.origin.y) * t;
	point.z = ray.origin.z + (z2 - ray.origin.z) * t;
	return true;
}

const Point& Plane::get_location() const
{
	return location;
}

const Material& Plane::get_material() const
{
	return material;
}
