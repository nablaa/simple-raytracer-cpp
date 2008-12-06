#include "matrix.hh"


Matrix3::Matrix3()
{
	elems[0][0] = 0;
	elems[0][1] = 0;
	elems[0][2] = 0;
	elems[1][0] = 0;
	elems[1][1] = 0;
	elems[1][2] = 0;
	elems[2][0] = 0;
	elems[2][1] = 0;
	elems[2][2] = 0;
}

Matrix3::Matrix3(const Vector3& row1, const Vector3& row2, const Vector3& row3)
{

}

Matrix3::Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{

}

Matrix3& Matrix3::operator+=(const Matrix3& other)
{

}

Matrix3& Matrix3::operator-=(const Matrix3& other)
{

}

Matrix3& Matrix3::operator*=(const Matrix3& other)
{

}

Matrix3& Matrix3::operator=(const Matrix3& other)
{

}

Matrix3 Matrix3::operator-() const
{

}

Vector3 Matrix3::col(size_t col) const
{

}

Vector3 Matrix3::operator[](size_t row) const
{

}

Vector3 Matrix3::mul(const Vector3& v) const
{

}

Matrix3 Matrix3::transpose() const
{

}

Matrix3 operator+(const Matrix3& left, const Matrix3& right)
{

}

Matrix3 operator-(const Matrix3& left, const Matrix3& right)
{

}

Matrix3 operator*(const Matrix3& left, const Matrix3& right)
{

}

std::ostream& operator<<(std::ostream& os, const Matrix3& vector)
{

}

