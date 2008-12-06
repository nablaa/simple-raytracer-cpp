#ifndef MATRIX_HH
#define MATRIX_HH

#include <iostream>
#include <cmath>
#include <stdexcept>
#include "vector.hh"

class Matrix3 {
public:
	Matrix3();
	Matrix3(const Vector3& row1, const Vector3& row2, const Vector3& row3);
	Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);

	Matrix3& operator+=(const Matrix3& other);
	Matrix3& operator-=(const Matrix3& other);
	Matrix3& operator*=(const Matrix3& other);
	Matrix3& operator=(const Matrix3& other);
	Matrix3 operator-() const;

	Vector3 col(size_t col) const;
	Vector3 operator[](size_t row) const;

	Vector3 mul(const Vector3& v) const;
	Matrix3 transpose() const;
	
	friend Matrix3 operator+(const Matrix3& left, const Matrix3& right);
	friend Matrix3 operator-(const Matrix3& left, const Matrix3& right);
	friend Matrix3 operator*(const Matrix3& left, const Matrix3& right);
	friend std::ostream& operator<<(std::ostream& os, const Matrix3& vector);

private:
	double elems[3][3];

};

Matrix3 operator+(const Matrix3& left, const Matrix3& right);
Matrix3 operator-(const Matrix3& left, const Matrix3& right);
Matrix3 operator*(const Matrix3& left, const Matrix3& right);
std::ostream& operator<<(std::ostream& os, const Matrix3& vector);

#endif // MATRIX_HH
