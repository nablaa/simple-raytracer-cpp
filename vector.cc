#include "vector.hh"

Vector3::Vector3(double x_, double y_, double z_) : x(x_), y(y_), z(z_)
{
}

Vector3::Vector3(const Point& point) : x(point.x), y(point.y), z(point.z)
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
	Vector3 v(-x, -y, -z);
	return v;
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
	Vector3 v(left.x + right.x, left.y + right.y, left.z + right.z);
	return v;
}

Vector3 operator-(const Vector3& left, const Vector3& right)
{
	Vector3 v(left.x - right.x, left.y - right.y, left.z - right.z);
	return v;
}

double dot(const Vector3& left, const Vector3& right)
{
	return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vector3 cross(const Vector3& a, const Vector3& b)
{
	Vector3 v(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	return v;
}

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

