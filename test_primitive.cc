#include <iostream>
#include <stdexcept>
#include "common.hh"
#include "primitive.hh"
#include "vector.hh"
#include "tests.hh"

bool operator==(const Point& l, const Point& r)
{
	return (float_equal(l.x, r.x) &&
	        float_equal(l.y, r.y) && float_equal(l.z, r.z));
}

int main()
{
	BEGIN_TESTS("Sphere");

	{
	Color red = { 1.0f, 0.0f, 0.0f };
	Material mat(red, 1.6, true);
	Point origin = { 0.0f, 0.0f, 0.0f };
	Sphere sp(mat, origin, 5.0);
	
	Vector3 v1(1, 0, 0);
	Point p = { -10.0f, 0.0f, 0.0f };
	Ray ray;
	ray.origin = p;
	ray.direction = &v1;

	Vector3 v2(-1, 0, 0);
	Ray ray2;
	ray2.origin = p;
	ray2.direction = &v2;

	Point p2 = { 7, 8, 9 };
	Vector3 v3(-3, -4, -5);
	Ray ray3;
	ray3.origin = p2;
	ray3.direction = &v3;

	Point p3 = { 7, 8, 9 };
	Vector3 v4(3, -1, -1);
	Ray ray4;
	ray4.origin = p3;
	ray4.direction = &v4;

	Point temp;
	
	TEST(sp.intersects(ray, temp), "intersects()");
	TEST(!sp.intersects(ray2, temp), "intersects(), 2");
	TEST(sp.intersects(ray3, temp), "intersects(), 3");
	TEST(!sp.intersects(ray4, temp), "intersects(), 4");
	}

	{
	Color red = { 1.0f, 0.0f, 0.0f };
	Material mat(red, 1.6, true);
	Point origin = { 4.6f, 2.8f, 9.3f };
	Sphere sp(mat, origin, 9.0);
	Point p = { 4.6, 2.8, 9.3 };

	TEST(p == sp.get_location(), "get_location()");
	}

	BEGIN_TESTS("Plane");

	{
	Color green = { 0.0f, 1.0f, 0.0f };
	Material mat(green);
	Point origin = { 1.0f, 5.0f, 9.0f };

	try {
		Plane(mat, origin, Vector3(0, 0, 0));
		TEST(false, "Plane()");
	} catch (std::runtime_error e) {
		TEST(true, "Plane()");
	}
	}

	{
	Color green = { 0.0f, 1.0f, 0.0f };
	Material mat(green);
	Point origin = { 1.0f, 5.0f, 9.0f };
	Vector3 n(1, 4, 5);
	Plane pl(mat, origin, n);
	Point p = { 1, 5, 9};

	TEST(pl.get_location() == p, "get_location()");
	}

	{
	Color green = { 0.0f, 1.0f, 0.0f };
	Material mat(green);
	Point origin = { 0.0f, 0.0f, 0.0f };
	Vector3 n(4, 0, 0);
	Plane pl(mat, origin, n);



	}


}

