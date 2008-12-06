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
	elems[0][0] = row1.get_x();
	elems[0][1] = row1.get_y();
	elems[0][2] = row1.get_z();
	elems[1][0] = row2.get_x();
	elems[1][1] = row2.get_y();
	elems[1][2] = row2.get_z();
	elems[2][0] = row3.get_x();
	elems[2][1] = row3.get_y();
	elems[2][2] = row3.get_z();
}

Matrix3::Matrix3(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33)
{
	elems[0][0] = a11;
	elems[0][1] = a12;
	elems[0][2] = a13;
	elems[1][0] = a21;
	elems[1][1] = a22;
	elems[1][2] = a23;
	elems[2][0] = a31;
	elems[2][1] = a32;
	elems[2][2] = a33;
}

Matrix3& Matrix3::operator+=(const Matrix3& other)
{
	elems[0][0] += other.elems[0][0];
	elems[0][1] += other.elems[0][1];
	elems[0][2] += other.elems[0][2];
	elems[1][0] += other.elems[1][0];
	elems[1][1] += other.elems[1][1];
	elems[1][2] += other.elems[1][2];
	elems[2][0] += other.elems[2][0];
	elems[2][1] += other.elems[2][1];
	elems[2][2] += other.elems[2][2];
	return *this;
}

Matrix3& Matrix3::operator-=(const Matrix3& other)
{
	elems[0][0] -= other.elems[0][0];
	elems[0][1] -= other.elems[0][1];
	elems[0][2] -= other.elems[0][2];
	elems[1][0] -= other.elems[1][0];
	elems[1][1] -= other.elems[1][1];
	elems[1][2] -= other.elems[1][2];
	elems[2][0] -= other.elems[2][0];
	elems[2][1] -= other.elems[2][1];
	elems[2][2] -= other.elems[2][2];
	return *this;
}

Matrix3& Matrix3::operator*=(const Matrix3& other)
{
	Matrix3 m;
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < 3; ++j) {
			double s = 0;
			for (size_t k = 0; k < 3; ++k) {
				s += elems[i][k] * other.elems[k][j];
			}
			m.elems[i][j] = s;
		}
	}
	*this = m;
	return *this;
}

Matrix3& Matrix3::operator=(const Matrix3& other)
{
	elems[0][0] = other.elems[0][0];
	elems[0][1] = other.elems[0][1];
	elems[0][2] = other.elems[0][2];
	elems[1][0] = other.elems[1][0];
	elems[1][1] = other.elems[1][1];
	elems[1][2] = other.elems[1][2];
	elems[2][0] = other.elems[2][0];
	elems[2][1] = other.elems[2][1];
	elems[2][2] = other.elems[2][2];
	return *this;
}

Matrix3 Matrix3::operator-() const
{
	return Matrix3(-elems[0][0], -elems[0][1], -elems[0][2], -elems[1][0], -elems[1][1],
	               -elems[1][2], -elems[2][0], -elems[2][1], -elems[2][2]);
}

Vector3 Matrix3::col(size_t col) const
{
	assert(col >= 1 && col <= 3);
	return Vector3(elems[0][col - 1], elems[1][col - 1], elems[2][col - 1]);
}

Vector3 Matrix3::operator[](size_t row) const
{
	assert(row >= 1 && row <= 3);
	return Vector3(elems[row - 1][0], elems[row - 1][1], elems[row - 1][2]);
}

double Matrix3::elem(size_t i, size_t j) const
{
	assert(i >= 1 && i <= 3 && j >= 1 && j <= 3);
	return elems[i - 1][j - 1];
}

Vector3 Matrix3::mul(const Vector3& v) const
{
	return Vector3(elems[0][0] * v.get_x() + elems[0][1] * v.get_y() + elems[0][2] * v.get_z(),
	               elems[1][0] * v.get_x() + elems[1][1] * v.get_y() + elems[1][2] * v.get_z(),
	               elems[2][0] * v.get_x() + elems[2][1] * v.get_y() + elems[2][2] * v.get_z());
}

Matrix3 Matrix3::transpose() const
{
	return Matrix3(elems[0][0], elems[1][0], elems[2][0], elems[0][1], elems[1][1], elems[2][1],
	               elems[0][2], elems[1][2], elems[2][2]);
}

Matrix3 operator+(const Matrix3& left, const Matrix3& right)
{
	Matrix3 m;
	m.elems[0][0] = left.elems[0][0] + right.elems[0][0];
	m.elems[0][1] = left.elems[0][1] + right.elems[0][1];
	m.elems[0][2] = left.elems[0][2] + right.elems[0][2];
	m.elems[1][0] = left.elems[1][0] + right.elems[1][0];
	m.elems[1][1] = left.elems[1][1] + right.elems[1][1];
	m.elems[1][2] = left.elems[1][2] + right.elems[1][2];
	m.elems[2][0] = left.elems[2][0] + right.elems[2][0];
	m.elems[2][1] = left.elems[2][1] + right.elems[2][1];
	m.elems[2][2] = left.elems[2][2] + right.elems[2][2];
	return m;
}

Matrix3 operator-(const Matrix3& left, const Matrix3& right)
{
	return left + (-right);
}

Matrix3 operator*(const Matrix3& left, const Matrix3& right)
{
	Matrix3 m = left;
	return m *= right;
}

std::ostream& operator<<(std::ostream& os, const Matrix3& matrix)
{
	os << "(";
	for (size_t i = 0; i < 3; ++i) {
		os << "(" << matrix.elems[i][0] << ", " << matrix.elems[i][1] << ", "
		   << matrix.elems[i][2] << ")";
	}
	os << ")";
	return os;
}


