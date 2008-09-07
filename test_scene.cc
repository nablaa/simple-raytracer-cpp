#include <iostream>
#include "scene.hh"
#include "vector.hh"
#include "common.hh"
#include "tests.hh"

int main()
{
	BEGIN_TESTS("Camera");

	{
	Point o = { 0, 0, 0 };
	Vector3 d(0, 0, 1);
	Vector3 a(0, -1, 0);
	size_t w = 800;
	size_t h = 600;
	double ratio = 10.0;
	Camera cam(o, d, a, w, h, ratio, 45.0);
	TEST(w == cam.get_width(), "get_width()");
	TEST(h == cam.get_height(), "get_height()");
	}

	{
	// TODO implement
	Point o = { 0, 0, 0 };
	Vector3 d(0, 0, 1);
	Vector3 a(0, -1, 0);
	size_t w = 100;
	size_t h = 100;
	double ratio = 10.0;
	Camera cam(o, d, a, w, h, ratio, 45.0);

	TEST(false, "shoot_ray()");
	}


	BEGIN_TESTS("Scene");

	{
	Point o = { 0, 0, 0 };
	Vector3 d(0, 0, 1);
	Vector3 a(0, -1, 0);
	size_t w = 100;
	size_t h = 100;
	double ratio = 10.0;
	Color bg = { 0, 0, 0 };
	Camera cam(o, d, a, w, h, ratio, 45.0);
	Scene sc(cam, bg);
	try {
		sc.add_object(NULL);
		TEST(false, "add_object()");
	} catch (std::runtime_error e) {
		TEST(true, "add_object()");
	}
	try {
		sc.add_light(NULL);
		TEST(false, "add_light()");
	} catch (std::runtime_error e) {
		TEST(true, "add_light()");
	}
	}

}

