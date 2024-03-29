#include "vector.hh"

Vector3::Vector3()
: x(0), y(0), z(0)
{
}

Vector3::Vector3(double x_, double y_, double z_)
: x(x_), y(y_), z(z_)
{
}

Vector3::Vector3(const Point& point)
: x(point.x), y(point.y), z(point.z)
{
}

Vector3::Vector3(const Point& p1, const Point& p2)
: x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z)
{
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-x, -y, -z);
}

double Vector3::length() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::normalize()
{
	double len = sqrt(x * x + y * y + z * z);
	if (len >= -0.001 && len <= 0.001) {
		throw std::runtime_error("vector length == 0");
	}
	x /= len;
	y /= len;
	z /= len;
	return *this;
}

Vector3 Vector3::mul(double n) const
{
	return Vector3(x * n, y * n, z * n);
}

double Vector3::get_x() const
{
	return x;
}

double Vector3::get_y() const
{
	return y;
}

double Vector3::get_z() const
{
	return z;
}

Vector3 operator+(const Vector3& left, const Vector3& right)
{
	return Vector3(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3 operator-(const Vector3& left, const Vector3& right)
{
	return Vector3(left.x - right.x, left.y - right.y, left.z - right.z);
}

double dot(const Vector3& left, const Vector3& right)
{
	return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vector3 cross(const Vector3& a, const Vector3& b)
{
	return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

