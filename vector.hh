#ifndef VECTOR_HH
#define VECTOR_HH

#include <iostream>
#include <cmath>
#include <stdexcept>

struct Point {
	double x, y, z;
};

class Vector3 {
public:
	Vector3();
	Vector3(double x, double y, double z);
	Vector3(const Point& point);
	Vector3(const Point& p1, const Point& p2);

	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);
	Vector3& operator=(const Vector3& other);
	Vector3 operator-() const;
	Vector3& normalize();
	double length() const;
	Vector3 mul(double n) const;

	double get_x() const;
	double get_y() const;
	double get_z() const;

	friend Vector3 operator+(const Vector3& left, const Vector3& right);
	friend Vector3 operator-(const Vector3& left, const Vector3& right);
	friend double dot(const Vector3& left, const Vector3& right);
	friend Vector3 cross(const Vector3& left, const Vector3& right);
	friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);

private:
	double x, y, z;
};

Vector3 operator+(const Vector3& left, const Vector3& right);
Vector3 operator-(const Vector3& left, const Vector3& right);
double dot(const Vector3& left, const Vector3& right);
Vector3 cross(const Vector3& left, const Vector3& right);
std::ostream& operator<<(std::ostream& os, const Vector3& vector);


#endif // VECTOR_HH
