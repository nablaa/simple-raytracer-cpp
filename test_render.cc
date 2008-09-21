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
	Color bg = { 0, 0, 200 };
	Camera cam(o, d, a, w, h, 90.0);
	Scene sc(cam, bg);

	// create objects
	Color green = { 0.0f, 1.0f, 0.0f };
	Color red = { 1.0f, 0.0f, 0.0f };
	Color blue = { 0.0f, 0.0f, 1.0f };
	Material mat(green);
	Material mat2(red);
	Material mat3(blue);
	Point origin = { 5.0f, 0.0f, 10.0f };
	Point origin2 = { -5.0f, 0.0f, 9.0f };
	Point origin3 = { 0.0f, 5.0f, 11.0f };
	Sphere sp(mat, origin, 3.0);
	Sphere sp2(mat2, origin2, 3.0);
	Sphere sp3(mat3, origin3, 3.0);
	sc.add_object(&sp);
	sc.add_object(&sp2);
	sc.add_object(&sp3);

	// create lights
	Point p = { 3, 10, 8 };
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

