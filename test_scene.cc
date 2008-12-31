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
	Matrix3 rot(1, 0, 0, 0, 1, 0, 0, 0, 1);
	size_t w = 800;
	size_t h = 600;
	Camera cam(o, rot, w, h);
	TEST(w == cam.get_width(), "get_width()");
	TEST(h == cam.get_height(), "get_height()");
	}

	BEGIN_TESTS("Scene");

	{
	Point o = { 0, 0, 0 };
	Matrix3 rot(1, 0, 0, 0, 1, 0, 0, 0, 1);
	size_t w = 100;
	size_t h = 100;
	Color bg = { 0, 0, 0 };
	Camera cam(o, rot, w, h);
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

