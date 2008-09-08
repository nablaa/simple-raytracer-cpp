#include <iostream>
#include "primitive.hh"
#include "scene.hh"
#include "vector.hh"
#include "common.hh"
#include "file.hh"
#include "tests.hh"

int main()
{
	BEGIN_TESTS("Rendering");

	{
	// initialize camera and scene
	Point o = { 0, 0, 0 };
	Vector3 d(0, 0, 1);
	Vector3 a(0, -1, 0);
	size_t w = 800;
	size_t h = 800;
	double ratio = 10.0;
	Color bg = { 0, 0, 200 };
	Camera cam(o, d, a, w, h, ratio, 90.0);
	Scene sc(cam, bg);

	// create objects
	Color green = { 0.0f, 1.0f, 0.0f };
	Color red = { 1.0f, 0.0f, 0.0f };
	Material mat(green);
	Material mat2(red);
	Point origin = { 600.0f, 0.0f, 0.0f };
	Point origin2 = { 610.0f, 5.0f, 1.0f };
	Point origin3 = { 610.0f, 0.0f, -5.0f };
	Sphere sp(mat, origin, 5.0);
	Sphere sp2(mat2, origin2, 3.0);
	Sphere sp3(mat2, origin3, 3.0);
	sc.add_object(&sp);
	sc.add_object(&sp2);
	sc.add_object(&sp3);

	// create lights
	Point p = { 600, 10, 50 };
	Light li1;
	li1.origin = p;
	li1.intensity = 1.0;
	sc.add_light(&li1);

	// rendering
	sc.render();

	// saving to file
	save_ppm("test_render_01.ppm", sc.get_imagedata());

	}

}

