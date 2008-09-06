#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "vector.hh"
#include "tests.hh"

bool operator==(const Vector3& l, const Vector3& r)
{
	return (float_equal(l.get_x(), r.get_x()) &&
	        float_equal(l.get_y(), r.get_y()) &&
	        float_equal(l.get_z(), r.get_z()));
}

bool operator!=(const Vector3& l, const Vector3& r)
{
	return !(l == r);
}

int main()
{
	BEGIN_TESTS("Vector3");

	{
	Vector3 v(4, -7, 10);
	Point p = {4, -7, 10};

	TEST(v == Vector3(p), "Vector3(const Point&)");
	}

	{
	Vector3 v1(2, 4, 5);
	Point p1 = {0, -3, 1};
	Point p2 = {2, 1, 6};

	TEST(v1 == Vector3(p1, p2), "Vector3(const Point&, const Point&)");
	}

	{
	Vector3 v1(1, 2, 3);
	Vector3 v2(1, 2, 3);

	TEST(v1 == v2, "operator==");
	}

	{
	Vector3 v1(3, 1, 6);
	Vector3 v2(-1, -2, 5);
	Vector3 v3(2, -1, 11);
	Vector3 v4(4, 3, 1);

	TEST(v1 != v2, "operator!=");
	TEST(v3 == v1 + v2, "operator+");
	TEST(v4 == v1 - v2, "operator-");
	}

	{
	Vector3 v1(-3, -5, -6);
	Vector3 v2(1, 9, 3);
	Vector3 v3(-2, 4, -3);
	v1 += v2;

	TEST(v3 == v1, "operator+=");
	}

	{
	Vector3 v1(6, 3, 2);
	Vector3 v2(-12, 23, -12);
	Vector3 v3(18, -20, 14);
	v1 -= v2;

	TEST(v3 == v1, "operator-=");
	}

	{
	Vector3 v1(5, 2, 7);
	Vector3 v2(-5, -2, -7);

	TEST(v1 == -v2, "operator-");
	}

	{
	Vector3 v1(5, 2, 7);
	Vector3 v2(23, -6, 6);
	v1 = v2;

	TEST(v1 == v2, "operator=");
	}

	{
	Vector3 v1(4, 6, -7);
	std::ostringstream oss;
	oss << v1;
	std::string str("(4, 6, -7)");

	TEST(oss.str() == str, "operator<<");
	oss << v1 << v1;
	}

	{
	Vector3 v1(2, -4, 3);
	Vector3 v2(0.371390676, -0.742781353, 0.557086015);
	v1.normalize();

	TEST(v1 == v2, "normalize()");
	}

	{
	Vector3 v1(0, 0, 0);
	try {
		v1.normalize();
		TEST(false, "normalize(), zero length");
	} catch (std::runtime_error e) {
		TEST(true, "normalize(), zero length");
	}

	}

	{
	Vector3 v1(1, 3, -5);
	Vector3 v2(4, -2, -1);
	double d = 3;

	TEST(float_equal(dot(v1, v2), d), "dot()");
	}

	{
	Vector3 v1(1, 2, 3);
	Vector3 v2(4, 5, 6);
	Vector3 v3(-3, 6, -3);

	Vector3 c = cross(v1, v2);
	TEST(c == v3, "cross()");
	}

	{
	Vector3 v1(2, 6, 9);
	Vector3 v2(0, 0, 0);

	TEST(float_equal(v1.length(), 11), "length()");
	TEST(float_equal(v2.length(), 0), "length(), 2");
	}
}


