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
	Color bg = { 0, 0, 0 };
	Camera cam(o, d, a, w, h, ratio, 45.0);
	Scene sc(cam, bg);

	// create objects
	Color green = { 0.0f, 1.0f, 0.0f };
	Material mat(green);
	Point origin = { 100.0f, 10.0f, -3.0f };
	Sphere sp(mat, origin, 1.0);
	sc.add_object(&sp);

	// rendering
	sc.render();

	// saving to file
	save_ppm("test_render_01.ppm", sc.get_imagedata());
	
	

	}


}

