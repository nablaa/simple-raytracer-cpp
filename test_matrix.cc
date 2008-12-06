#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "matrix.hh"
#include "vector.hh"
#include "tests.hh"

bool operator==(const Vector3& l, const Vector3& r)
{
	return (float_equal(l.get_x(), r.get_x()) &&
	        float_equal(l.get_y(), r.get_y()) &&
	        float_equal(l.get_z(), r.get_z()));
}

bool operator==(const Matrix3& l, const Matrix3& r)
{
	return (l[1] == r[1] && l[2] == r[2] && l[3] == r[3]);
}

bool operator!=(const Matrix3& l, const Matrix3& r)
{
	return !(l == r);
}

int main()
{
	BEGIN_TESTS("Matrix3");

	{
	Vector3 zero;
	Matrix3 m;
	TEST(zero == m[1] && zero == m[2] && zero == m[3], "Matrix3()");
	}

	{
	Vector3 v1(1, 2, 3);
	Vector3 v2(4, 5, 6);
	Vector3 v3(7, 8, 9);
	Matrix3 m(v1, v2, v3);
	TEST(v1 == m[1] && v2 == m[2] && v3 == m[3], "Matrix3(const Matrix3& row1, const Matrix3& row2, const Matrix3& row3)");
	}

	{
	Vector3 v1(1, 2, 3);
	Vector3 v2(4, 5, 6);
	Vector3 v3(7, 8, 9);
	Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3 m2(v1, v2, v3);
	TEST(m1 == m2, "double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33");
	}

	{
	Vector3 v1(1, 2, 3);
	Vector3 v2(4, 5, 6);
	Vector3 v3(7, 8, 9);
	Matrix3 m1(v1, v2, v3);
	Matrix3 m2(v2, v1, v3);
	m1 += m2;
	TEST(m1 == Matrix3(v1 + v2, v1 + v2, v3 + v3), "Matrix3& operator+=(const Matrix3& other)");
	}

	{
	Vector3 v1(1, 2, 3);
	Vector3 v2(4, 5, 6);
	Vector3 v3(7, 8, 9);
	Matrix3 m1(v1, v2, v3);
	Matrix3 m2(v2, v1, v3);
	m1 -= m2;
	TEST(m1 == Matrix3(v1 - v2, v1 - v2, v3 - v3), "Matrix3& operator-=(const Matrix3& other)");
	}

	{
	Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3 m2(2, 3, 4, 5, 6, 7, 8, 9, 10);
	m1 *= m2;
	TEST(m1 == Matrix3(36, 42, 48, 81, 96, 111, 126, 150, 174), "Matrix3& operator*=(const Matrix3& other)");
	}

	{
	Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3 m2(2, 3, 4, 5, 6, 7, 8, 9, 10);
	m1 = m2;
	TEST(m1 == Matrix3(2, 3, 4, 5, 6, 7, 8, 9, 10), "Matrix3& operator=(const Matrix3& other)");
	}

	{
	Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	TEST(-m == Matrix3(-1, -2, -3, -4, -5, -6, -7, -8, -9), "Matrix3 operator() const");
	}

	{
	Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Vector3 v1(1, 4, 7);
	Vector3 v2(2, 5, 8);
	Vector3 v3(3, 6, 9);
	TEST(m.col(1) == v1 && m.col(2) == v2 && m.col(3) == v3, "Vector3 col(size_t col) const");
	}

	{
	Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Vector3 v1(1, 2, 3);
	Vector3 v2(4, 5, 6);
	Vector3 v3(7, 8, 9);
	TEST(m[1] == v1 && m[2] == v2 && m[3] == v3, "Vector3 operator[](size_t row) const");
	}

	{
	Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Vector3 v1(1, 2, 3);
	TEST(m.mul(v1) == Vector3(30, 36, 42), "Vector3 mul(const Vector3& v) const");
	}

	{
	Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	TEST(m.transpose() == Matrix3(1, 4, 7, 2, 5, 8, 3, 6, 9), "Matrix3 transpose() const");
	}

	{
	Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3 m2(2, 3, 4, 5, 6, 7, 8, 9, 10);
	Matrix3 m3 = m1 + m2;
	TEST(m3 == Matrix3(3, 5, 7, 9, 11, 13, 15, 17, 19), "Matrix3 operator+(const Matrix3& left, const Matrix3& right)");
	}

	{
	Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3 m2(2, 3, 4, 5, 6, 7, 8, 9, 10);
	Matrix3 m3 = m1 - m2;
	TEST(m3 == Matrix3(-1, -1, -1, -1, -1, -1, -1, -1, -1), "Matrix3 operator-(const Matrix3& left, const Matrix3& right)");
	}

	{
	Matrix3 m1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3 m2(2, 3, 4, 5, 6, 7, 8, 9, 10);
	Matrix3 m3 = m1 * m2;
	TEST(m3 == Matrix3(36, 42, 48, 81, 96, 111, 126, 150, 174), "Matrix3 operator*(const Matrix3& left, const Matrix3& right)");
	}

	{
	Matrix3 m(1, 2, 3, 4, 5, 6, 7, 8, 9);
	std::ostringstream oss;
	oss << m;
	std::string str("((1, 2, 3), (4, 5, 6), (7, 8, 9))");

	TEST(oss.str() == str, "operator<<");
	}

}


